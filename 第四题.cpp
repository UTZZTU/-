#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	int number;
	char name[100];
	int num1,num2,num3;
	double pjf;
};
int main ()
{
	struct student s[5];
	FILE *fp;
	int i,n,num1,num2,num3,k,sum;
	double q;
	char name[100];
	if((fp=fopen("stu_new.txt","r"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	k=0;
	sum=0;
	for(i=0;i<6;i++)
	{
		fscanf(fp,"%d  %s  %d,%d,%d  %lf",&n,name,&num1,&num2,&num3,&q);
		if(n!=101)
		{
			s[k].number=n;
			strcpy(s[k].name,name);
			s[k].num1=num1;
			s[k].num2=num2;
			s[k].num3=num3;
			s[k].pjf=q;
			if(n==102)
			{
				strcpy(s[k].name,"Xiang");
			}
			k++;
		}
		if(n==103)
		{
			printf("%d  %s  %d,%d,%d  %lf\n",n,name,num1,num2,num3,q);
		}
		else
		sum++;
	}
	if(sum==6)
	printf("Can not find!\n");
	fclose(fp);
	if((fp=fopen("stu_new.txt","w+"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	for(i=0;i<5;i++)
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
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%d  %s  %d,%d,%d  %lf",&n,name,&num1,&num2,&num3,&q);
		printf("%d  %s  %d,%d,%d  %lf\n",n,name,num1,num2,num3,q);
	}
	fclose(fp);
	return 0;
}
