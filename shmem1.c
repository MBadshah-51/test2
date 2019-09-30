#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#define DNFBS -1
#define DFBS   0
#define DRBC   1

typedef struct shared_mem
{
	int status;
	char data[3][50];
}shared_mem;

void main(int argc,char **argv)
{
	shared_mem *shm_ptr;
	int i,n;
	int shm_id;
	
	key_t key=ftok("shmfile",'A');
	shm_id= shmget(key,sizeof(shared_mem),IPC_CREAT|0666);
	
	shm_ptr=shmat(shm_id,NULL,0);
	shm_ptr->status=DNFBS;
	
	for(i=1;i<argc;i++)
		strcpy(shm_ptr->data[i-1],argv[i]);
	
	shm_ptr->status=DFBS;
	
	while(shm_ptr->status != DRBC)
	{
		sleep(1);
		printf("reading...");
	}
	
	printf("\nRead by client!");
	
	shmdt(shm_ptr);
	shmctl(shm_id,IPC_RMID,NULL);
	
	
}


/*
SERVER OUTPUT:-

badshah@mujahid-Predator--5PH3151:~$ gcc shmem1.c
badshah@mujahid-Predator--5PH3151:~$ ./a.out this is SINHGAD
reading...reading...reading...reading...reading...reading...
Read by client!badshah@mujahid-Predator--5PH3151:~$ 

*/
