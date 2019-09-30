#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


void main(int argc,char *argv[])
{
	int i,arr[10],key,index;
	
	printf("\nThis is search.");
	
	for(i=0;i<argc-1;i++)
	{
		arr[i]=atoi(argv[i+1]);
	}
	
	printf("\nArray = ");
	printArray(arr,argc-1);
	
	printf("\nEnter the element to search in array: ");
	scanf("%d",&key);
	
	index=binarySearch(arr,0,argc-2,key);
	
	if(index==-1)
	{
		printf("\nElement is not present in array.");
	}
	else
	{
		printf("\nElement present in array at index %d",index);
	}
	
	
	
}
