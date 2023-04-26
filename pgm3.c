#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/wait.h>
void main()
{
pid_t pid;
int ch;
char f[50];
struct stat buf;
DIR *d;
struct dirent *de;
do
{
printf("Enter your choice : \n1.fork\n2.get pid\n3.wait &exit\n4.exec\n5.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: pid=fork();
			if(pid == 0)
			printf("Child Process with id = %d \n",getpid());
			else
			printf("Parent Process wit id = %d \n",getpid());
			break;
			
case 2: printf("Process id of the calling process =%d\n",getpid());
			break;

case 3: pid=fork();
			int status;
			if(pid == 0)
			{
			printf("Child\n");
			sleep(1.0);
			exit(10);
			}
			else
			{
			printf("Parent\n"); 
			wait(& status);
			printf("Exit Status is %d\n",WEXITSTATUS(status));}
			break;

case 4: execl("/usr/bin/ls","ls","-l",NULL);
			break;
case 5:exit(0);
			break;
}
}
while(ch != 5);
}



