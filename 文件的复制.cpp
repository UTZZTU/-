#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE*fp1,*fp2;
	char ch,sfile[20],dfile[20];
	printf("����Դ�ļ�����");
	scanf("%s",sfile);
	printf("����Ŀ���ļ�����"); 
	scanf("%s",dfile);
	if((fp1=fopen(sfile,"r"))==NULL)
	{
		printf("can,t open file:%s",sfile);
		exit(0);
	 } 
	 if((fp2=fopen(dfile,"w"))==NULL)
	 {
	 	printf("can,t open file:%s",dfile);
	 	exit(0);
	 }
	 while((ch=fgetc(fp1))!=EOF)
	 fputc(ch,fp2);
	 fclose(fp1);
	 fclose(fp2);
	 return 0;
}
