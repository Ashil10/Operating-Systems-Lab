#FACTORIAL OF N NATURAL NOS. USING BASH SCRIPT
echo "Enter the number"
read n
fact=1 
for((i=1;i<=n;i++))
{
    fact=$((fact * i))
}
echo "Factorial of $n is $fact"
