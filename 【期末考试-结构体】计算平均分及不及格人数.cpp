#include <stdio.h>
struct student
{
	int number;
	char name[200];
	int num;
};
double fun(struct student s[],int n)
{
	int i;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum+=s[i].num;
	}
	return sum*1.0/n;
}
int main ()
{
	struct student s[100];
	int n,i,rs=0;
	double sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d",&s[i].number,s[i].name,&s[i].num);
	}
sum=fun(s,n);
	for(i=0;i<n;i++)
	{
		if(s[i].num<60)
		rs++;
	}
	printf("%.2f\n",sum);
	printf("%d",rs);
	return 0;
}
