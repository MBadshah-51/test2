#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<semaphore.h>

#define THINKING 0
#define EATING 1
#define HUNGRY 2

pthread_mutex_t lock,pr;
int state[]={THINKING,THINKING,THINKING,THINKING,THINKING};
sem_t forks[5];


int check(int temp)
{
	int next=(temp+1)%5,prev=(temp+4)%5;
	
	int eating=0;
	
	pthread_mutex_lock(&lock);
	if(state[next]!=EATING && state[prev]!=EATING)
	{
		eating=1;
		sem_wait(&forks[temp]);
		sem_wait(&forks[(temp+1)%5]);
		state[temp]=EATING;
	}
	pthread_mutex_unlock(&lock);
	if(eating)
		return 1;
	
	return 0;
}

void print()
{
	int i;
	
	pthread_mutex_lock(&pr);
	for(i=0;i<5;i++)
	{
		if(state[i]==THINKING)
			printf("\nPhilosopher %d is THINKING",i);
			
		else if(state[i]==EATING)
			printf("\n Philospher %d is EATING.",i);
		else
			printf("\nPhilosopher %d is HUNGRY",i);
	}
	pthread_mutex_unlock(&pr);
}

void *eat(void *arg)
{
	int id=*(int *)arg;
	int ate=0;
	
	state[id]=HUNGRY;
	
	while(1)
	{
		ate=check(id);
		if(ate)
		{	
			print();
			sleep(2);
			sem_post(&forks[id]);
			sem_post(&forks[(id+1)%5]);
			state[id]=THINKING;
			break;
		}
	}
	
}

int main()
{
	int i;
	//	pthread_mutex_init	
	pthread_t	philosopher[5];
	
	for(i=0;i<5;i++)
		sem_init(&forks[i],0,1);
	
	for(i=0;i<5;i++)
	{
		int *temp=(int*)malloc(sizeof(int));
		*temp=i;
		pthread_create(&philosopher[i],NULL,eat,temp);
	}
	for(i=0;i<5;i++)
		pthread_join(philosopher[i],NULL);
		
	printf("\n");

}
