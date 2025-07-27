#include <stdio.h>
#include <stdlib.h>
struct student
{
	int number;
	char name[100];
	int num1,num2,num3;
	double pjf;
};
#define N 6
int main ()
{
	struct student s[N],p;
	FILE*fp;
	int i,n,num1,num2,num3;
	char name[100];
	double q;
	scanf("%d %s %d,%d,%d",&s[0].number,s[0].name,&s[0].num1,&s[0].num2,&s[0].num3);
	s[0].pjf=(s[0].num1+s[0].num2+s[0].num3)*1.0/3;
	if((fp=fopen("stu_sort.txt","r"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=1;i<N;i++)
	{
	  fscanf(fp,"%d  %s  %d,%d,%d  %lf",&s[i].number,s[i].name,&s[i].num1,&s[i].num2,&s[i].num3,&s[i].pjf);
	}
	for(i=0;i<5;i++)
	{
		if(s[i].pjf<s[i+1].pjf)
		{
			p=s[i+1];
			s[i+1]=s[i];
			s[i]=p;
		}
	}
	if((fp=fopen("stu_new.txt","w"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d  %s  %d,%d,%d  %lf\n",s[i].number,s[i].name,s[i].num1,s[i].num2,s[i].num3,s[i].pjf);
	}
	fclose(fp);
	if((fp=fopen("stu_new.txt","r"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	printf("输出学生信息：\n");
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%d  %s  %d,%d,%d  %lf",&n,name,&num1,&num2,&num3,&q);
		printf("%d  %s  %d,%d,%d  %lf\n",n,name,num1,num2,num3,q);
	}
	fclose(fp);
	return 0;
}
