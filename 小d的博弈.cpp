#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int get_x(int n)
{
	int res=0;
	while(n!=1&&n!=2)
	{
		res++;
		if(n&1)
		{
			n=n/2;
		}
		else
		{
			n=n/2-1;
		}
	}
	return res;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if((n==1||n==2)&&(m==1||m==2))
		{
			printf("Bob\n");
		}
		else if((n==1||n==2)||(m==1||m==2))
		{
			printf("Alice\n");
		}
		else
		{
			int res1=get_x(n),res2=get_x(m);
			if(res1==1&&res2==1)
			{
				printf("Bob\n");
			}
			else if(res1==1&&res2==2||res1==2&&res2==1)
			{
				printf("Alice\n");
			}
			else if(res1==2&&res2==2)
			{
				printf("Bob\n");
			}
			else if(res1==2||res2==2)
			{
				printf("Alice\n");
			}
			else
			{
				printf("Bob\n");
			}
		}
	}
	return 0;
}