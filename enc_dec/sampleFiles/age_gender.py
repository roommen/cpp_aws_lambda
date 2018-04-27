import cv2
import os
import time
import numpy as np
from wide_resnet import WideResNet
from keras.utils.data_utils import get_file
import datetime
import pandas as pd
import mysql.connector
from kafka import KafkaConsumer,KafkaProducer
import dlib
import scipy.misc
from collections import Counter
#initialising detection model and shape predictor
face_detector = dlib.get_frontal_face_detector()
shape_predictor = dlib.shape_predictor('shape_predictor_68_face_landmarks.dat')
face_recognition_model = dlib.face_recognition_model_v1('dlib_face_recognition_resnet_model_v1.dat')
TOLERANCE = 0.5
def get_face_encodings(image):
    detected_faces = face_detector(image, 1)
    shapes_faces = [shape_predictor(image, face) for face in detected_faces]
    return [np.array(face_recognition_model.compute_face_descriptor(image, face_pose, 1)) for face_pose in shapes_faces]
def compare_face_encodings(known_faces, face):
    return (np.linalg.norm(known_faces - face, axis=1) <= TOLERANCE)
def find_match(known_faces, names, face):
    matches = compare_face_encodings(known_faces, face)
    count = 0
    for match in matches:
        if match:
            return names[count]
        count += 1
    return 'Not Found'
train_data = []
train_id = []
face_id = 0
model = WideResNet(64,16,8)()
fpath = "pretrained_models/weights.18-4.06.hdf5"
model_dir = os.path.join(os.getcwd(), "pretrained_models").replace("//", "\\")
model.load_weights(fpath)
def draw_label(image, point, label, font=cv2.FONT_HERSHEY_SIMPLEX,
                   font_scale=1, thickness=2):
        size = cv2.getTextSize(label, font, font_scale, thickness)[0]
        x, y = point
        cv2.rectangle(image, (x, y - size[1]), (x + size[0], y), (255, 0, 0), cv2.FILLED)
        cv2.putText(image, label, point, font, font_scale, (255, 255, 255), thickness)
def crop_face(imgarray, section, margin=40, size=64):
        """
        :param imgarray: full image
        :param section: face detected area (x, y, w, h)
        :param margin: add some margin to the face detected area to include a full head
        :param size: the result image resolution with be (size x size)
        :return: resized image in numpy array with shape (size x size x 3)
        """
        img_h, img_w, _ = imgarray.shape
        if section is None:
            section = [0, 0, img_w, img_h]
        (x, y, w, h) = section
        margin = int(min(w,h) * margin / 100)
        x_a = x - margin
        y_a = y - margin
        x_b = x + w + margin
        y_b = y + h + margin
        if x_a < 0:
            x_b = min(x_b - x_a, img_w-1)
            x_a = 0
        if y_a < 0:
            y_b = min(y_b - y_a, img_h-1)
            y_a = 0
        if x_b > img_w:
            x_a = max(x_a - (x_b - img_w), 0)
            x_b = img_w
        if y_b > img_h:
            y_a = max(y_a - (y_b - img_h), 0)
            y_b = img_h
        cropped = imgarray[y_a: y_b, x_a: x_b]
        resized_img = cv2.resize(cropped, (size, size), interpolation=cv2.INTER_AREA)
        resized_img = np.array(resized_img)
        return resized_img, (x_a, y_a, x_b - x_a, y_b - y_a)


faceCascade = cv2.CascadeClassifier("pretrained_models/haarcascade_frontalface_default.xml")
frames = []
index = 0
consumer = KafkaConsumer('age',bootstrap_servers =['extrack.bridgei2i.in:9092'])
producer =  KafkaProducer(bootstrap_servers='Extrack.bridgei2i.in:9092')
producer2 =  KafkaProducer(bootstrap_servers='Extrack.bridgei2i.in:9092')
topic = 'data'
try:
    consumer.poll()
    consumer.seek_to_end()
except:
    print "latest"
    # infinite loop, break by key ESC
while True:
    msg = next(consumer)
    # Capture frame-by-frame
    nparr = np.fromstring(msg.value, np.uint8)
    flags = cv2.IMREAD_COLOR
    #converting ndarray to image matrix
    frame = cv2.imdecode(nparr,flags)
    ret,jpeg = cv2.imencode('.png', frame)    
    #convert ndarray into bytes and sending to kafka server
    producer.send('output', jpeg.tobytes())
    frames.append(frame)
    face_size =64
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(face_size, face_size),
	flags=cv2.CASCADE_SCALE_IMAGE
    )
    face_imgs = np.empty((1, face_size, face_size, 3))
    for face in faces:
        face_img, cropped = crop_face(frame, face, margin=40, size=face_size)
        (x, y, w, h) = cropped
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 200, 0), 2)
        test = frame[y-int(.21*y):y+h+int(.21*y),x-int(.13*x):x+h+int(.13*x),:]
        #cv2.imwrite('test.jpg',test)
        #cv2.imwrite('new.jpg',frame)
        face_imgs[0,:,:,:] = face_img
        results = model.predict(face_imgs)
        predicted_genders = results[0]
        ages = np.arange(0, 101).reshape(101, 1)
        predicted_ages = results[1].dot(ages).flatten()
        gender = 'F' if results[0][0][0]>0.5 else 'M'
        age = predicted_ages[0]
        timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
	try:    
		face_encodings_in_image = get_face_encodings(face_img)
		if len(train_data)==0:
		    train_data.append(face_encodings_in_image[0])
		    cv2.imwrite('test/face'+str(face_id)+'.jpg',test)
		    train_id.append(str(face_id))
		    fid = face_id
		    face_id = face_id +1
		try:
		    match = find_match(train_data,train_id, face_encodings_in_image[0])
		    if match!='Not Found':
			fid = match
			#cv2.putText(frame,str(match),(x-20,y-20),cv2.FONT_HERSHEY_SIMPLEX,1,(0,255,255),2)
		    else:
			train_data.append(face_encodings_in_image[0])
			cv2.imwrite('test/face'+str(face_id)+'.jpg',test)
			train_id.append(str(face_id))
			fid = face_id
			face_id = face_id +1
		except:
		    continue
		print timestamp,fid,age,gender
		producer2.send(topic,timestamp+','+str(age)+','+gender+','+str(fid))
	except:
		continue
cv2.destroyAllWindows()
