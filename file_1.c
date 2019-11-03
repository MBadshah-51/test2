#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>  
int cnt;
struct record
{
    int roll;
    int id;
    char name[100];
    char branch[100];
    
};

int main()
{
    int fd , fd1;
    char ch;
    int no , no2 , no3;
    int flag = 0;
    
    char filename[100] , filename1[100];
    struct record r;
    int cnt = 0;
    int n1;
    
    printf("Enter a filename");
    scanf("%s",filename);
    int n;
    
    do
    {
    printf("Enter your choice\n");
    printf("1.Insert\n2.Display\n3.Search\n4.Delete\n5.Update");
    scanf("%d",&n);
    
    switch(n)
    {
    
    case 1:
    printf("Enter contents in your file...");
     fd = open(filename,O_CREAT|O_WRONLY|O_APPEND,0666);
    
     
     printf("\nEnter roll no");
     scanf("%d",&r.roll);
     
     printf("\nEnter id");
     scanf("%d",&r.id);
     
     printf("\nEnter name");
     scanf("%s",r.name);
     
      printf("\nEnter branch name");
     scanf("%s",r.branch);
     
     write(fd,&r,sizeof(r));            //write
      close(fd);
      break;
     
     case 2:
     printf("Contents in your records are\n");
      fd = open(filename,O_RDONLY,0666); //read
      printf("Rollno.  ID  Name  Branch\n");
     while(read(fd,&r,sizeof(r)) != 0)
     {
        printf("%d  ",r.roll);
        printf("%d  ",r.id);
        printf("%s  ",r.name);
        printf("%s",r.branch);
        printf("\n");
       
     }
      close(fd);
      break;
      
      case 3:
      
      printf("Enter roll no. that you want to search");
      scanf("%d",&no);
      
      fd = open(filename,O_RDONLY,0666);
      
      while(read(fd,&r,sizeof(r))!=0)
      {
            if(r.roll==no)
            {
            printf("\nroll no . is present\n");
            flag = 1;
         
            }
            
      }
     if(flag==0)
     printf("\nroll no. not  present\n");
     close(fd);
        
      break;
      
      case 4:
      
      printf("\nEnter a roll no. that you want to delete..\n");
      scanf("%d",&no2);
      
      fd = open(filename,O_RDONLY,0666);
      
      fd1 = open("hey",O_CREAT|O_WRONLY,0666);
      
      while(read(fd,&r,sizeof(r))!=0)
      {
        if(r.roll!=no2)
        {
            write(fd1,&r,sizeof(r));
        
        
        }
      
      }
      close(fd);
      close(fd1);
      
      
      remove(filename);
      rename("hey",filename);
      
      fd = open(filename,O_RDONLY,0666); //read
      printf("Rollno.  ID  Name  Branch\n");
     while(read(fd,&r,sizeof(r)) != 0)
     {
        printf("%d  ",r.roll);
        printf("%d  ",r.id);
        printf("%s  ",r.name);
        printf("%s",r.branch);
        printf("\n");
       
     }
      close(fd);
      
      break;
      
      case 5:
      
      printf("Enter roll no  that you want to update\n");
      scanf("%d",&no3);
      
      fd = open(filename,O_RDONLY,0666);
      
      int fd2 = open("hey1",O_CREAT|O_WRONLY,0666);
      
      while(read(fd,&r,sizeof(r))!=0)
      {
        if(r.roll!=no3)
        {
            write(fd2,&r,sizeof(r));
        }
        else
        {
            printf("\nEnter NEW roll no\n");
            scanf("%d",&r.roll);
            
            printf("\nEnter NEW id\n");
            scanf("%d",&r.id);
            
            printf("Enter NEW name\n");
            scanf("%s",r.name);
            
            printf("Enter NEW branch\n");
            scanf("%s",r.branch);
            
            write(fd2,&r,sizeof(r));
        
        
        }
      
      }
      
      close(fd);
      close(fd2);
      
      remove(filename);
      rename("hey1",filename);
      
        fd = open(filename,O_RDONLY,0666); //read
     printf("Rollno.  ID  Name  Branch\n");
     while(read(fd,&r,sizeof(r)) != 0)
     {
        printf("%d  ",r.roll);
        printf("%d  ",r.id);
        printf("%s  ",r.name);
        printf("%s",r.branch);
        printf("\n");
       
     }s
      close(fd);
      
      break;
          
     }//switch
      printf("\nWant to repeat some operation(1/0)\n");
      scanf("%d",&n1);
      }while(n1==1);
      
      
return 0;


}
