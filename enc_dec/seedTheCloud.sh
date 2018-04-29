#!/bin/bash

# Edit the below variables with your values as per requirement
# 1. sn - Serial No
# 2. ac - Authorization Code
sn="BOS-774999580613"
ac="YWU-FFM"

# Provide name of the file for encryption
filename="age_gender.py"

# You would be prompted for entering the S3 Bucket Name, AWS_Access_Key_ID and AWS_Secret_Access_Key
echo -n "Enter S3 Bucket Name of AWS (files will be uploaded here) :: "
read bucketName
echo -n "Enter AWS Access Key ID :: "
read accessKey
echo -n "Enter AWS Secret Access Key :: "
read secretAccessKey

# Call the Makefile to create genPP dynamically (for PoC perspective)
make -C genPP install

# Invoke genPP with SN and AC to generate custom passphrase.h
cd genPP; ./genPP $sn $ac; cd ..

# Copy passphrase.h to customerEncDec and node folder
cd genPP; cp passphrase.h ../customerEncDec; cd ..
cd genPP; cp passphrase.h ../node; cd ..

# Create custom executable with the customer's password
make -C customerEncDec install

# Invoke customerEncDec with the filename to encrypt
cd customerEncDec; ./customerEncDec "encrypt" $filename; cd ..
cd sampleFiles; rm -f $filename; cd ..

# Invoke customerEncDec with the filename.enc to decrypt
cd customerEncDec; ./customerEncDec "decrypt" $filename; cd ..
cd sampleFiles; rm -f *.enc; cd ..

# Use boto s3 to upload them into bucket
