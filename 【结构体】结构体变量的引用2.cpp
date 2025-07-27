#include <stdio.h>
# define n 3
struct birthday
{
	int year;
	int month;
	int day;
};
struct money
{
	int jcgz;
	int jt;
	int zcbt;
};
struct teacher
{
	int number[5];
	char name[100];
	char zc[100];
	struct money sum;
	struct birthday csrq;
};
int main ()
{
	struct teacher w[n];
	int i,j,rs=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
	{
		scanf("%d",&w[i].number[j]);
	}

	scanf("%s%s",w[i].name,w[i].zc);
	scanf("%d%d%d",&w[i].sum.jcgz,&w[i].sum.jt,&w[i].sum.zcbt);
	scanf("%d%d%d",&w[i].csrq.year,&w[i].csrq.month,&w[i].csrq.day);
	if((w[i].sum.jcgz+w[i].sum.jt+w[i].sum.zcbt)>5000)
	rs++;
	}
	for(i=0;i<n;i++)
	{
		if((w[i].sum.jcgz+w[i].sum.jt+w[i].sum.zcbt)>5000)
		{
			printf("姓名：%s，出生日期：%d.%d.%d，工资：%d",w[i].name,w[i].csrq.year,w[i].csrq.month,w[i].csrq.day,(w[i].sum.jcgz+w[i].sum.jt+w[i].sum.zcbt));
			rs--;
		}
		if(rs!=0)
		printf("\n");
	}
	return 0;
}
