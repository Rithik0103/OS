echo "Operations :- "
echo "1.Add"
echo "2.sub"
echo "3.mul"
echo "4.Div"
echo "5.mod"

echo "Enter choice [1-5] : "
read c

echo "Enter a :"
read a
echo "Enter b :"
read b

case $c in
	1)
		r=$((a + b))
		operator="+"
		;;
	2)
                r=$((a - b))
                operator="-"
                ;;
	3)
                r=$((a * b))
                operator="*"
                ;;
	4)
                r=$((a / b))
                operator="/"
                ;;
	5)
                r=$((a % b))
                operator="%"
                ;;
	*)
                echo "Invalid choice"
		exit 1
		;;
esac

echo "$a $operator $b = $r"
