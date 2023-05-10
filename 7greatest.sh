echo "Enter a : "
read a
echo "Enter b : "
read b
if [ "$a" -ge "$b" ];
then 
	echo "a=$a is greater"
elif [ "$b" -ge "$a" ];
then
	echo "b=$b is greater"
else
	echo "Equal"
fi
