#include <stdio.h>
struct student
{
	long long int number;
	char name[100];
	int num1,num2,num3;
};
int main ()
{
	struct student s[200];
		int i,sum=0,n;
		while(scanf("%d",&n)!=EOF)
		{
			for(i=0;i<n;i++)
	{
		scanf("%lld%s%d%d%d",&s[i].number,s[i].name,&s[i].num1,&s[i].num2,&s[i].num3);
	}
		for(i=0;i<n;i++)
	{
		if((s[i].num1+s[i].num2+s[i].num3)>270)
		{
			printf("%lld %s %d %d %d\n",s[i].number,s[i].name,s[i].num1,s[i].num2,s[i].num3);
		}
	}
		}
	
	return 0;
}
