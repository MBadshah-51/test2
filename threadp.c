#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>


int a[5][5],b[5][5];
int c[5][5];
int row1,col1,row2,col2;

typedef struct sele{
	int rowele,colele;
}sele;


void *multiply(void* larg)
{
	int prod,sum=0,k;
	
	sele *obj;
	obj=(sele *)larg;
	
	for(k=0;k<col1;k++)
	{
		
		sum+=a[obj->rowele][k] * b[k][obj->colele];
		//printf("a=%d,b=%d,sum=%d\t",a[obj->rowele][k],b[k][obj->colele],sum);
	}
	//printf("\n");
	intptr_t s= sum;
	pthread_exit((void *)s);
	//return ((void*)prod);
}

void matdisp(int mat[5][5],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		{
			printf("\n");
			for(j=0;j<c;j++)
			{
				printf("%d\t",mat[i][j]);
			}
		}
	printf("\n");
}

void main()
{
		int i,j,k,count;
		void *val;
		pthread_t tid[50];
		sele S;
		
		while(1)
		{
		
			printf("\nMatrix multiplication");
			printf("\nEnter the no. of rows and cols in matrix 1: ");
			scanf("%d%d",&row1,&col1);
				
			printf("\nEnter the no. of rows and cols in  matrix 2: ");
			scanf("%d%d",&row2,&col2);
			
			if(col1==row2)
				break;
				
			else
				{
					printf("\nError!");
					printf("\nThe number of columns in matrix1 should be equal to number in rows of matrix2. ");
				}
			
		}
		
		printf("\nEnter the elements in matrix 1(row wise) : \n");
		for(i=0;i<row1;i++)
			for(j=0;j<col1;j++)
				scanf("%d",&a[i][j]);
				
		printf("\nEnter the elements in matrix 2(row wise) : \n");
		for(i=0;i<row2;i++)
			for(j=0;j<col2;j++)
				scanf("%d",&b[i][j]);
				
				
		printf("\nThreading");
		
		for(i=0,count=0;i<row1;i++)
			for(j=0;j<col2;j++)
			{
				sele *S=(sele *)malloc(sizeof(sele));
				S->rowele=i;
				S->colele=j;
				
				pthread_create(&tid[count++],NULL,multiply,S);
           			
			}
		
		for(i=0,count=0;i<row1;i++)
			for(j=0;j<col2;j++)
				{
					pthread_join(tid[count++],&val);
					c[i][j]=(intptr_t)val;
				}
		
		printf("\nMatrix 1: \n");
		matdisp(a,row1,col1);
		
		printf("\nMatrix 2: \n");
		matdisp(b,row2,col2);
		
		printf("\nResultant Matrix: \n");
		matdisp(c,row1,col2);
		
		
}

/*
badshah@mujahid-Predator--5PH3151:~$ gcc -pthread threadp.c
badshah@mujahid-Predator--5PH3151:~$ ./a.out

Matrix multiplication
Enter the no. of rows and cols in matrix 1: 2
3

Enter the no. of rows and cols in  matrix 2: 3

4

Enter the elements in matrix 1(row wise) : 
1
1
1
1
1
1

Enter the elements in matrix 2(row wise) : 
1
1
1
1
1
1
1
1
3
4
1
1

Threading: 
	

Matrix 1: 

1	1	1	
1	1	1	

Matrix 2: 

1	1	1	1	
1	1	1	1	
3	4	1	1	

Resultant Matrix: 

5	6	3	3	
5	6	3	3	
badshah@mujahid-Predator--5PH3151:~$ 


*/
