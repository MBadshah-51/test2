#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


void main(int argc, char *argv[])
{
	
	int n,i,arr[10],id;
	pid_t pid;
	printf("\nThis is first...");
	
	for(i=0;i<argc-1;i++)
		arr[i]=atoi(argv[i+1]);
		
	printf("\nEntered array is: ");
	printArray(arr,argc-1);
	
	bubbleSort(arr,argc-1);
	
	printf("\nSorted array is: ");
	printArray(arr,argc-1);
	
	for(i=0;i<argc-1;i++)
		{
			sprintf(argv[i+1],"%d",arr[i]);
			
		}
	
	id=fork();
	
	printf("\nProcess id is=%d",getpid());
	
	if(id==0)
	{
		printf("\nThis is child process.");
		printf("\nProcess  id is=%d",getpid());
		printf("\nParent process id is=%d",getppid());
		
		
		execv("search",argv);
	}
	
	if(id>0)
	{
		printf("\nThis is parent process.");
		wait(NULL);
	}
/**************************************************************************************************/

OUTPU:-


badshah@mujahid-Predator--5PH3151:~$ ./a.out 10 25 45 7 3

This is first...
Entered array is: 10 25 45 7 3 

Sorted array is: 3 7 10 25 45 

Process id is=3212

Process id is=3213
This is child process.
Process  id is=3213

This is search.
Array = 3 7 10 25 45 

Enter the element to search in array: 10

Element present in array at index 2
This is parent process.
badshah@mujahid-Predator--5PH3151:~$
	
}

