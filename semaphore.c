#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>


int buffer_size=5,buffer[5]={0};
sem_t empty,full;
pthread_mutex_t m;
int k=0,l=0,arr[5]={0};
pthread_t pid[5];
pthread_t cid;
static int i=1;

void *prod(void *arg)
{
	int *a=arg,x,count=0;
	while (count<4)
	{
		
			sem_wait(&empty);
			pthread_mutex_lock(&m);
			
			//printf("\n\n Enter %dth value: ",i);
			//scanf("%d",&x);
			printf("\nProducer%d produces %d at index %d.",*a,i,k);
			
			buffer[k]=i;
			i++;
			k=(k+1)%buffer_size;
			
			
			pthread_mutex_unlock(&m);
			sem_post(&full);
			count++;
		
	}
}

void *con(void *arg)
{
	int count=20;
	while(count>0)
	{
		sem_wait(&full);
		pthread_mutex_lock(&m);
		
		//arr[l]=buffer[l];
		printf("\nConsumed  ;value=%d, index=%d",buffer[l],l);
		
		l=(l+1)%(buffer_size);
		count--;
		
		pthread_mutex_unlock(&m);
		sem_post(&empty);
	}
}

void main()
{
	int i,val;
	
	
	sem_init(&empty,0,5);
	sem_init(&full,0,0);
	
	for(i=0;i<buffer_size;i++)
	{	
		pthread_create(&pid[i],NULL,prod,(void*)&i);
		
	}
		pthread_create(&cid,NULL,con,(void*)&i);
	
	for(i=0;i<buffer_size;i++)
	{
		pthread_join(pid[i],NULL);
	}
	
	
	pthread_join(cid,NULL);
	printf("\n");
	
}

/*

badshah@mujahid-Predator--5PH3151:~$ gcc -pthread semaphore.c
badshah@mujahid-Predator--5PH3151:~$ ./a.out

Producer1 produces 1 at index 0.
Producer2 produces 2 at index 1.
Producer2 produces 3 at index 2.
Producer4 produces 4 at index 3.
Producer5 produces 5 at index 4.
Consumed  ;value=1, index=0
Consumed  ;value=2, index=1
Consumed  ;value=3, index=2
Consumed  ;value=4, index=3
Consumed  ;value=5, index=4
Producer0 produces 6 at index 0.
Producer0 produces 7 at index 1.
Producer0 produces 8 at index 2.
Producer0 produces 9 at index 3.
Producer0 produces 10 at index 4.
Consumed  ;value=6, index=0
Consumed  ;value=7, index=1
Producer1 produces 11 at index 0.
Producer1 produces 12 at index 1.
Consumed  ;value=8, index=2
Consumed  ;value=9, index=3
Consumed  ;value=10, index=4
Producer1 produces 13 at index 2.
Consumed  ;value=11, index=0
Consumed  ;value=12, index=1
Producer1 produces 14 at index 3.
Producer1 produces 15 at index 4.
Producer1 produces 16 at index 0.
Producer2 produces 17 at index 1.
Consumed  ;value=13, index=2
Consumed  ;value=14, index=3
Producer3 produces 18 at index 2.
Producer3 produces 19 at index 3.
Consumed  ;value=15, index=4
Consumed  ;value=16, index=0
Consumed  ;value=17, index=1
Consumed  ;value=18, index=2
Consumed  ;value=19, index=3
Producer4 produces 20 at index 4.
Consumed  ;value=20, index=4
badshah@mujahid-Predator--5PH3151:~$
*/
