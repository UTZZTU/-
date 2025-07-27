#include <stdio.h>
struct student
{
	long long int number;
	char name[300];
	int num;
};
int main ()
{
	struct student s[100];
	int n,i,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld%s%d",&s[i].number,s[i].name,&s[i].num);
			if(s[i].num>sum)
			{
				sum=s[i].num;
			}
		}
		for(i=0;i<n;i++)
		{
			if(s[i].num==sum)
			{
				printf("%lld %s %d\n",s[i].number,s[i].name,s[i].num);
				break;
			}
		}
	}
	return 0;
}
