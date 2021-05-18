#!/bin/bash

#Creating file name
fileName="BatchJob"
fileName="${fileName}$RANDOM"

#Creating the new file
touch $fileName

#Informing user of the file created
echo $fileName

