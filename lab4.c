#include<stdio.h>
#include <stdlib.h>
int out=-1;
int in=-1;
int buffer[100];
int size;
void display()
{int i;
if(in==-1)
printf("Empty");
else
{
printf("THE PRODUCER CURRENTLY HAS\n");
for(i=in;i!=out;i=(i+1)%size)
printf("%d ",buffer[i]);
}
printf("%d ",buffer[i]);
printf("\n");
}
void consumer()
{
if(out ==-1)
printf("Empty \n");
else if (in ==out)
{
printf("Consumed --> %d\n",buffer[in]);
in=out=-1;
printf("Empty\n");
}
else
{
printf("Consumed --> %d\n",buffer[in]);
in=(in+1)%size;
}
}

void producer()
{
int data;
printf("Enter the data produced\n");
scanf("%d",&data);
if(in==-1)
{
in=out=0;
buffer[out]=data;
}
else if((out == size-1 && in==0)||(out+1==in))
printf("FULL\n");
else
{
out=(out+1)%size;
buffer[out]=data;
}}
void main()
{
printf("Enter the size \n");
scanf("%d",&size);
int ch;
do
{
printf("Enter 1 for Producer \nEnter 2 for Consumer \nEnter 3 for Displaying\nEnter 4 to Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: producer();
			break;
			
case 2: consumer();
			break;

case 3: display();
			break;

case 4:exit(0);
}}
while(ch !=4);
}
