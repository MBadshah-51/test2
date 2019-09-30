#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
	 int i=0,n;
	 char x,buff[100],str[50];
	 
	 printf("\nEnter the text(use '#' to terminate):-\n");
	 
	
	 
	 while((x=getchar())!='#')
	 	buff[i++]=x;
	 	
	 buff[i]='\0';
	// printf("\n\n%s",buff);	
	 
	  
	 mkfifo("fifo1",0666);
	 int fd= open("fifo1",O_WRONLY);
	 write(fd,buff,strlen(buff)+1);
	 close(fd);
	 sleep(5);
	 
	 
	 
	 int fd1 = open("fifo2",O_RDONLY);
	 read(fd1,str,sizeof(str));
	 
	 
	 printf("\n%s",str);
	 close(fd1);
	 return 0;
}

/*
OUTPUT:

pipe1:
badshah@mujahid-Predator--5PH3151:~/o2$ gcc pipe1.c -o pipe1
badshah@mujahid-Predator--5PH3151:~/o2$ ./pipe1

Enter the text(use '#' to terminate):-
hello ubuntu.
this is me.
sinhgad college of engineering.#


Characters =57 ,words =9,lines =3.
badshah@mujahid-Predator--5PH3151:~/o2$


pipe2:

badshah@mujahid-Predator--5PH3151:~/o2$ gcc pipe2.c -o pipe2
badshah@mujahid-Predator--5PH3151:~/o2$ ./pipe2

String: hello ubuntu.
this is me.
sinhgad college of engineering.
57,9,3
57,9,3badshah@mujahid-Predator--5PH3151:~/o2$ 
*/
