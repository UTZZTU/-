#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
	char ch;
	FILE*fp;
	if((fp=fopen("file1.txt","w"))==NULL)
	{
		printf("Can not open this file!\n");
		exit(0);
	}
	do
	{
		ch=getchar();
		fputc(ch,fp);
	}while(ch!='\n');
	fclose(fp);
	return 0;
}
