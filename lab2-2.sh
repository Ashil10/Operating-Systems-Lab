#PRIME CHECKER USING BASH SCRIPT
echo "Enter Number "
read n
for((i=2; i<=$n/2; i++))
{
  ans=$(( n%i ))
  if [ $ans -eq 0 ]
  then
    echo "$n is not a prime number."
    exit 0
  fi
}
echo "$n is a prime number."

