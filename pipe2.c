#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main()
{
	int i;
	int chars=0,words=0,lines=0;
	int fd1,fd2;
	char str[100],ans[50],c[3][5];
	
	fd1= open("fifo1",O_RDONLY);
	
	memset(str,'\0',sizeof(str));
	read(fd1,str,sizeof(str));
	printf("\nString: %s",str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ' || str[i]!='	' || str[i]!='\n')
			chars++;
		
		if(str[i]==' ' || str[i]=='	' || str[i]=='\n' )
			words++;
			
		if(str[i]=='\n')
			lines++;
	}
	words++;
	lines++;
	close(fd1);
	printf("\n%d,%d,%d",chars,words,lines);
	
	sprintf(c[0],"%d",chars);
	sprintf(c[1],"%d",words);
	sprintf(c[2],"%d",lines);
	
	printf("\n%s,%s,%s",c[0],c[1],c[2]);
	
	FILE *fp;
	fp= fopen("count.txt","w");
	fprintf(fp,"Characters =%s ,words =%s,lines =%s.",c[0],c[1],c[2]);
	fclose(fp);
	
	mkfifo("fifo2",0666);
	fd2 = open("fifo2",O_WRONLY);
	
	fp=fopen("count.txt","r");
	
	i=0;
	while(!feof(fp))
		ans[i++]=fgetc(fp);
		
	fclose(fp);
	
	write(fd2,ans,strlen(ans)+1);
	close(fd2);
	return 0;
}
