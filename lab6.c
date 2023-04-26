#include<stdio.h>
int nb,np,blocks[100],processes[100],alloc[100];
void process_input()
{
printf("Enter the number of blocks\n");
scanf("%d",&nb);
printf("Enter the memory spaces required for each block\n");
for(int i=0;i<nb;i++)
scanf("%d",&blocks[i]);
printf("Enter the number of processes\n");
scanf("%d",&np);
printf("Enter the spaces required for each process:\n");
for(int i=0;i<np;i++)
{
scanf("%d",&processes[i]);
alloc[i]=1;
}
}

void display()
{
printf("\nPID\tProcess Size\tBlock No.\n");
for(int i=0;i<np;i++)
{
printf("%d\t%d\t",i+1,processes[i]);
if(alloc[i]==-1)
printf("\tNot Allocated\n");
else
printf("\t%d\n",alloc[i]+1);
}
}

void first_fit()
{
process_input();
for(int i=0;i<np;i++)
{
for(int j=0;j<nb;j++)
{
if(processes[i]<=blocks[j])
{
alloc[i]=j;
blocks[j]-=processes[i];
break;
}
else
alloc[i]=-1;
}
}
display();
}

void best_fit()
{
process_input();
int index,min,i,j;
for(int i=0;i<np;i++)
{
min=10000,index=-1;
for(int j=0;j<nb;j++)
{
if(blocks[j]>=processes[i] && blocks[j]<min)
{
min=blocks[j];
index=j;
}
}
if(index!=-1)
{
alloc[i]=index;
blocks[index]-=processes[i];
}
}
display();
}

void worst_fit()
{
int i,j,max,index;
process_input();
for(i=0;i<np;i++)
{
max=-1,index=-1;
for(j=0;j<nb;j++)
{
if((blocks[j]>=processes[i]) && (blocks[j]>max))
{
max=blocks[j];
index=j;
}
}
if(index!=-1)
{
alloc[i]=index;
blocks[index]-=processes[i];
}
else
alloc[i]=-1;
}
display(); 
}

void main()
{
int ch=0;
do
{
printf("MENU\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\n4.EXIT\nEnter Choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:first_fit();
			break;
case 2:best_fit();
			break;
case 3:worst_fit();
			break;
}
}while(ch!=4);
}
