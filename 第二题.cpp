#include <stdio.h>
#include <stdlib.h>
struct student
{
	int number;
	char name[100];
	int num1,num2,num3;
	double pjf;
};
#define N 5
int main ()
{
	struct student s[N],p;
	FILE*fp;
	int i,j,n,num1,num2,num3;
	char name[100];
	double q;
	if((fp=fopen("stud.txt","r"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%d  %s  %d,%d,%d  %lf",&s[i].number,s[i].name,&s[i].num1,&s[i].num2,&s[i].num3,&s[i].pjf);
	}
	fclose(fp);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(s[j].pjf<s[j+1].pjf)
			{
				p=s[j+1];
				s[j+1]=s[j];
				s[j]=p;
			}
		}
	}
	if((fp=fopen("stu_sort.txt","w"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d  %s  %d,%d,%d  %lf\n",s[i].number,s[i].name,s[i].num1,s[i].num2,s[i].num3,s[i].pjf);
	}
	fclose(fp);
	if((fp=fopen("stu_sort.txt","r"))==NULL)
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
