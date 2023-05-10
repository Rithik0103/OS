echo "Enter range : "
read r

for i in {1..$r}
do 
	echo "$i $(($i * $i))"
done
