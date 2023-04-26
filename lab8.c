#include<stdio.h>
#include<stdlib.h>
struct req
{
int data;
struct req *next;
}*head,*tail;
int mutex,pid=-1,time;
void enreadyq(int data)
{
struct req *newnode=(struct req *)malloc(sizeof(struct req));
newnode->data=data;
newnode->next=0;
if(head==0)
head=tail=newnode;
else
{
tail->next=newnode;
tail=newnode;
}
}
int dereadyq(int bt[],int ct[],int completed[],int t)
{
if(head!=0)
{
pid=head->data;
if(bt[pid]>t)
{
ct[pid]=mutex=time+t;
bt[pid]-=t;
}
else
{
ct[pid]=mutex=time+bt[pid];
completed[pid]=1;
}
head=head->next;
return pid;
}
return -1;
}
void main()
{
int choice;
while(1)
{
time =-1,mutex=-1;
printf("\n\n\1.ROUND ROBIN\n\2.SRTF\n3.PREMPTIVE PRIORITY\n4.EXIT");
printf("\n\tEnter your choice");
scanf("%d",&choice);
if(choice==4)
exit(0);
int n,t;
printf("Enter the no. of processes: ");
scanf("%d",&n);
int at[n],bt[n+1],btt[n],index[n],copy[n],ct[n],completed[n],pri[n+1];
if(choice==3)
printf("Enter the arrival and burst time & priority of processes: ",n);
else
printf("Enter the arrival and burst time of  process: ",n);
for(int i=0;i<n;i++)
{
if(choice==3)
scanf("%d%d%d",&at[i],&bt[i],&pri[i]);
else
scanf("%d%d",&at[i],&bt[i]);
index[i]=i;
copy[i]=at[i];
ct[i]=0;
completed[i]=0;
btt[i]=bt[i];
}
if(choice==1)
{
printf("Enter the time quantum");
scanf("%d",&t);}
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(copy[j]>copy[j+1])
{
int temp1=copy[j];
copy[j]=copy[j+1];
copy[j+1]=temp1;
int temp2=index[j];
index[j]=index[j+1];
index[j+1]=temp2;

}
}
}
if(choice==1)
{
int inx=-1;
while(time!=100)
{
time ++;
inx ++;
while(inx<n)
{
if(at[index[inx]]==time)
{
if(mutex<time)
mutex=time;
enreadyq(index[inx]);
}
else
{
inx-=1;
break;
}
inx++;
}
if(time==mutex)
{
if(pid!=-1 && completed[pid]==0)
enreadyq(pid);
pid=dereadyq(bt,ct,completed,t);
}
}
}
else if(choice ==2)
{
int inx;
while(time!=100)
{
bt[n]=1000;
int srtf=n;
time++;
inx=0;
while(inx<n)
{
if(at[index[inx]]<=time)
{
if(bt[index[inx]]<bt[srtf] && bt[index[inx]]!=0)
srtf=index[inx];
}
else
break;
inx++;
}
ct[srtf]=time+1;
bt[srtf]-=1;
}}
else if(choice ==3)
{
int inx,high_pri;
while(time!=100)
{
pri[n]=-1;
high_pri=n;
time++;
inx=0;
while(inx<n)
{
if(at[index[inx]]<=time)
{
if(pri[index[inx]]>pri[high_pri] && bt[index[inx]]!=0)
high_pri=index[inx];
}
else
break;
inx++;
}
ct[high_pri]=time+1;
bt[high_pri]-=1;
}



}
printf("PID\t\tARRIVAL\t\tBURST\t\tCOMPLETION\t\tTURNAROUND\t\tWAITING\n");
double avg_tat=0,avg_wt=0;
for(int i=0;i<n;i++)
{
avg_tat+=ct[i]-at[i];
avg_wt+=ct[i]-at[i]-btt[i];
printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1,at[i],btt[i],ct[i],ct[i]-at[i],ct[i]-at[i]-btt[i]);
}
printf("Average Turn Around Time : %f\n Average Waiting Time : %f\n",avg_tat/n,avg_wt/n);
}
}






























