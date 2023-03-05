#SUM OF N NATURAL NOS USING BASH SCRIPT
echo "Enter the limit"
read n
sum=0
for((i=0;i<=n;i++))
{
sum=$(( sum + i ))
}
echo "Sum of $n natural nos. is $sum"