#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE*fp;
	int n,num1,num2,num3,i;
	double pjf;
	char s[100];
	if((fp=fopen("stud.txt","w"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=1;i<=5;i++)
	{
		scanf("%d %s %d,%d,%d",&n,s,&num1,&num2,&num3);
		pjf=(num1+num2+num3)*1.0/3;
		fprintf(fp,"%d  %s  %d,%d,%d  %lf\n",n,s,num1,num2,num3,pjf);
	}
	fclose(fp);
	if((fp=fopen("stud.txt","r"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=1;i<=5;i++)
	{
		fscanf(fp,"%d  %s  %d,%d,%d  %lf",&n,s,&num1,&num2,&num3,&pjf);
		printf("%d  %s  %d,%d,%d  %lf\n",n,s,num1,num2,num3,pjf);
	}
	fclose(fp);
	return 0;
}
