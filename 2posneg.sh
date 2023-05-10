echo "Enter the number:"
read n
if [ $n -ge 0 ]
then
	echo "Its a positive number"
elif [ $n -lt 0 ]
then
	echo "Its a negative number"
else
	echo "Its not positive or negative number"
fi
