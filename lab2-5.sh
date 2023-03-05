#FLOYD'S TRIANGLE USING BASH SCRIPT
echo "Enter the rows"
read r
count=1
echo "Floyd's Triangle"
for((i=1;i<=r;i++))
{
    for((j=1;j<=i;j++))
    {
        echo -n "$count "
        count=$((count + 1 ))
    }
    echo""
}