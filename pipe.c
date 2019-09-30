#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

void main()
{
	FILE *fp;
	int p1[2],p2[2];	//p[0]-> read	//p[1]->write
	char str[100],filename[20];
	pipe(p1);
	pipe(p2);
	pid_t id;
	int i=0;
	
	
	
	id=fork();
	
	if(id==0)
	{
		printf("\nThis is child process: \n");
		
		close(p1[1]);//close write end 
		
		read(p1[0],filename,sizeof(filename));
		
		fp=fopen(filename,"r");
		
		while(!feof(fp))
		{
			str[i++]=fgetc(fp);
			
		}
		
		close(p2[0]);
		write(p2[1],str,strlen(str)+1);
	}
	
	if(id>0)
	{
		printf("\nThis is parent process: \n");
		printf("\nEnter filename: ");
		scanf("%s",filename);
	//gets(filename);
	
		close(p1[0]); //close read end
		write(p1[1],filename,strlen(filename)+1);
		
		wait(NULL);
		
		close(p2[1]);
		
		read(p2[0],str,sizeof(str));
		
		printf("\nContents of file: \n");
		printf("%s",str);
		
	}
	
}
/*
read.txt:

Hello  ubuntu.
This is me.
sinhgad college of engineering.
*/

/*
OUTPUT:

badshah@mujahid-Predator--5PH3151:~$ gcc pipe.c
badshah@mujahid-Predator--5PH3151:~$ ./a.out

This is parent process: 
Enter filename: 
This is child process: 
read.txt

Contents of file: 
Hello  ubuntu.
This is me.
sinhgad college of engineering.
badshah@mujahid-Predator--5PH3151:~$ 
*/
