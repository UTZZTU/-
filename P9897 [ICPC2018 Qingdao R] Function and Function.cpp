#include <bits/stdc++.h>
using namespace std;
int t,x,k,f[10]={1,0,0,0,1,0,1,0,2,1};
int solve(int x)
{
	int res=0;
	if(x==0) return f[0];
	while(x)
	{
		res+=f[x%10];
		x/=10;
	}
	return res;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&k);
		for(int i=1;i<=k;i++)
		{
			x=solve(x);
			if(x==0)
			{
				if((k-i)%2==0)
				{
					x=0;
				}
				else
				{
					x=1;
				}
				break;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}

