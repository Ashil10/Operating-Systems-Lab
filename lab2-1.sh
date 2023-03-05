#Menu Driven Pgm for Simple Calc using Bash Script
echo "Enter two numbers"
read a
read b
i=1
while [ $i -eq 1 ]
do
    echo "Enter 1 for addition"
    echo "Enter 2 for subtraction"
    echo "Enter 3 for multiplication"
    echo "Enter 4 for division"
    echo "Enter 5 to exit"
    echo "Enter your choice "
    read ch
    case $ch in
    1)res=$(( $a + $b ))
            echo "Sum of $a and $b is $res";;
            
    2)res=$(( $a - $b ))
            echo "Difference of $a and $b is $res";;
            
    3)res=$(( $a * $b ))
            echo "Product of $a and $b is $res";;
            
    4)res=$(( $a/$b ))
            echo "Quotient of $a and $b is $res";;
    5)echo "Quitting..."
        exit;;
    esac
    
done





