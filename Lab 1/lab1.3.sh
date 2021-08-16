#Name: Vincent Yu
#Date: 01/08/2020
#Title: Lab1 - sample program with area of circle computation
#Description: This program computes the area of a rectangle given the user inputted height and width of a rectangle. It also computes the area of a circle given the user inputted radius of a circle. The program only continues to compute the areas of rectangles and circles if the user's name is 'vyu1'. Otherwise the program ends. The program uses the bc (basic calculator) to compute floating decimal point calculations because Shell cannot do that.


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

#Your usename
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
#Make sure usename matches
if [ $user = "vyu1" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi

response="Yes"
response1="Yes"
while [ $response != "No" ]
do
        #User input rectangle height
        echo "Enter height of rectangle: "
        read height
	#User input rectangle width
        echo "Enter width of rectangle: "
        read width
	#Calculate rectangle area
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"
	#Repeat computation or not
        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response
done

if [ $response == "No" ] 
then
        #Ask if you want to compute circle area
        echo "Would you like to compute the area of a circle? [Yes/No]?"
        read response1
fi

while [ $response1 != "No" ]
do
        #User input circle radius
        echo "Enter radius of circle: "
        read radius
	#pi variable
	pi=3.14
	#Calculate circle area
	area1=$(echo "scale=2; $radius*$radius*$pi" | bc)
        echo "The area of the circle is $area1"
	#Ask if repeat computation or not
	echo "Would you like to repeat for another circle [Yes/No]?"
	read response1

done
