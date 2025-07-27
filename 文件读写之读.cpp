#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE*fp;
	char ch;
	if((fp=fopen("file2.txt","r"))==NULL)
	{
		printf("Can not open this file!\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	putchar(ch);
	fclose(fp);
	return 0;
}
