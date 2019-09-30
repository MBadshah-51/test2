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

void main()
{
	shared_mem *shm_ptr;
	int i,n;
	int shm_id;
	
	key_t key=ftok("shmfile",'A');
	
	shm_id=shmget(key,sizeof(shared_mem),IPC_CREAT|0666);
	
	shm_ptr=shmat(shm_id,NULL,0);
	
	printf("\nContent read: ");
	
	for(i=0;i<3;i++)
		printf("\n%s",shm_ptr->data[i]);
	
	printf("\n");
	shm_ptr->status=DRBC;
	shmdt(shm_ptr);
	
}


/*
CLIENT OUTPUT:-

badshah@mujahid-Predator--5PH3151:~$ gcc shmem2.c
badshah@mujahid-Predator--5PH3151:~$ ./a.out

Content read: 
this
is
SINHGAD
badshah@mujahid-Predator--5PH3151:~$ 
*/
