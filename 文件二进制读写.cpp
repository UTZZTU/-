#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE*fp;
	int a[10],b[10]={0},i;
	if((fp=fopen("int_file.dat","wb"))==NULL)
	{
		printf("Can not open this file!\n");
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
    fwrite(a,sizeof(int),10,fp);
    fclose(fp);
    if((fp=fopen("int_file.dat","rb"))==NULL)
    {
    	printf("Can not open this file!\n");
		exit(0);
	}
    fread(b,sizeof(int),10,fp);
    for(i=0;i<10;i++)
    {
    	printf("%4d",b[i]);
	}
	fclose(fp);
	return 0;
}
