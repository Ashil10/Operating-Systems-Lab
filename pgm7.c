#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t chopstick[5];
int eat(int n);
void *philos(void *n)
{
int ph=*(int *)n;
printf("Philosopher %d wanted to eat\n",ph);
printf("Philosopher %d tries to pick left chopstick\n",ph);
sem_wait(&chopstick[(ph+1)%5]);
printf("Philosopher %d picks left chopstick\n",ph);
printf("Philosopher %d tries to pick right chopstick\n",ph);
sem_wait(&chopstick[(ph)]);
printf("Philosopher %d picks right chopstick\n",ph);
eat(ph);
sleep(2);
printf("Philosopher %d has finished eating\n",ph);
sem_post(&chopstick[(ph+1)%5]);
printf("Philosopher %d leaves right chopstick\n",ph);
sem_post(&chopstick[ph]);
printf("Philosopher %d leaves left chopstick\n",ph);
}
int eat(int n)
{
printf("Philosopher %d begins to eat\n",n);
}
void main()
{
int i,n[5];
pthread_t T[5];
for(i=0;i<5;i++)
sem_init(&chopstick[i],0,1);
for(i=0;i<5;i++)
{
n[i]=i;
pthread_create(&T[i],NULL,philos,(void *)&n[i]);
}
for(i=0;i<5;i++)
pthread_join(T[i],NULL);
}


 
