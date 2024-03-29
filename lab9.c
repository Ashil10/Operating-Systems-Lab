#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*newnode,*temp;

int search(int pid,int pno,struct node *hashtable[]){
    temp=hashtable[pid-1];
    int count=1;
    while(count!=pno){
        count++;
        temp=temp->next;
    }
    return temp->data;
}


void main(){
    int n,m,p,pno,fno,offset,pid,memsize;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    printf("Enter total size of memory: ");
    scanf("%d",&memsize);
    printf("Enter the number of frames in the memory: ");
    scanf("%d",&m);
    int framesize=memsize/m;
    struct node *hashtable[n];
    for(int i=0;i<n;i++){
        hashtable[i]=0;
        printf("\nEnter the number of pages for procees P%d: ",i+1);
        scanf("%d",&p);
        printf("\n\t\tProcess %d",i+1);
        for(int j=1;j<=p;j++){
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter frameno allocated to page %d(Enter -1 if page not loaded to frame): ",j);
            scanf("%d",&newnode->data);
            newnode->next=0;
            if(hashtable[i]==0)
                hashtable[i]=temp=newnode;
            else{
                temp->next=newnode;
                temp=newnode;
            }
        }
    }

    while(1){
        printf("\nEnter the logical address(ProcessID,PageNumber,Offset): ");
        scanf("%d",&pid);
        scanf("%d",&pno);
        scanf("%d",&offset);
        fno=search(pid,pno,hashtable);
        if(fno==-1)
            printf("The page was not loaded to memory");
        else
            printf("The physical address is %d",(fno-1)*framesize + offset);
    }
}

 
