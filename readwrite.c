#include<stdio.h>

#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

char FILENAME[10];
char str[]="HELLO";
sem_t reading,writing;
pthread_mutex_t mutex;
int readno=0;

void *writer(void *arg)
{	
	int id=*(int *)arg;
	FILE *fptr;
	sem_wait(&writing);
	
	fptr=fopen(FILENAME,"a+");
	
	fprintf(fptr,"%s",str);
	printf("\nWriter %d wrote %s",id,str);
	fclose(fptr);
	
	sem_post(&writing);
	
}

void *reader(void *arg)
{
	FILE *fptr;
	int id=*(int *)arg;
	sem_wait(&reading);
	readno++;
	
	if(readno==1){
		sem_wait(&writing);
	}
	
	char arr[50];
	fptr=fopen(FILENAME,"r");
	fscanf(fptr,"%s",arr);
	printf("\n\tReader %d read from file:\n\t%s\n",id,arr);
	
	readno--;
	if(readno==0){
		sem_post(&writing);
	}
	
	sem_post(&reading);
	
}

int main()
{
	int i,j;
	sem_init(&writing,0,1);
	sem_init(&reading,0,5);
	pthread_t wid[5],rid[5];
	
	printf("\nEnter the file name: ");
	scanf("%s",FILENAME);
	
	for(i=0;i<5;i++)
		pthread_create(&wid[i],NULL,writer,(void*)&i);
	
	for(i=0;i<5;i++)
		pthread_create(&rid[i],NULL,reader,(void*)&i);
	
	for(i=0;i<5;i++)
		pthread_join(wid[i],NULL);
	
	for(i=0;i<5;i++)
		pthread_join(rid[i],NULL);
	
}
