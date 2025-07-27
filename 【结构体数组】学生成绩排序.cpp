#include <stdio.h>
struct student
{
	long long int number;
	char name[100];
	int num;
};
int main ()
{
	struct student s[200],st;
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld%s%d",&s[i].number,s[i].name,&s[i].num);
		}
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(s[j].num<s[j+1].num)
				{
					st=s[j];
					s[j]=s[j+1];
					s[j+1]=st;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%lld %s %d\n",s[i].number,s[i].name,s[i].num);
		}
	}
	return 0;
}
