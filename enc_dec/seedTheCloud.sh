#!/bin/bash

# Edit the below variables with your values as per requirement
# 1. sn - Serial No
# 2. ac - Authorization Code
sn="BOS-774999580613"
ac="YWU-FFM"


# You would be prompted for entering the S3 Bucket Name, AWS_Access_Key_ID and AWS_Secret_Access_Key
echo -n "Enter S3 Bucket Name of AWS (files will be uploaded here) :: "
read bucketName
echo -n "Enter AWS Access Key ID :: "
read accessKey
echo -n "Enter AWS Secret Access Key :: "
read secretAccessKey

# Change this to genPP as the target in the Makefile
./mainPP $sn $ac
