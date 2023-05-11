echo "enter year"
read y
if [ $(( y % 4 )) -eq 0 ]
then 
	echo "Its a leap year"
else 
	echo "Its not a leap year"
fi
