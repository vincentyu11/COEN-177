#Name: Vincent Yu
#Date: 01/08/2020
#Title: Lab1 - sample program with change to user name
#Description: This program computes the area of a rectangle give the user inputted height and width of the rectangle. The program only continues to ask for the rectangle dimenstions if the user's name is "vyu1". Otherwise the program ends.


#Sample shell programs for Lab assignment 
#!/bin/sh
#directory
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$

#your username
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
#make sure username matches
if [ $user = "vyu1" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        #User input height
        echo "Enter height of rectangle: "
        read height
	#User input width
        echo "Enter width of rectangle: "
        read width
	#Calculate area of rectangle
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"
	#Repeat computation or not
        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response

done
