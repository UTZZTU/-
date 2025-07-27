#include <bits/stdc++.h>
using namespace std;
#define re register
bool st[1000010];
int prime[1000010],cnt,n;
int main ()
{
	st[1]=true;
	for(re int i=2;i<=1000000;++i)
	{
		if(!st[i]) prime[cnt++]=i;
		for(re int j=0;prime[j]<=1000000/i;++j)
		{
			st[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
		break;
		int a,b,flag=0;
		for(re int i=0;;i++)
		{
			if(prime[i]&1)
			{
				if(!st[n-prime[i]])
				{
					printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
					flag=1;
				}
			}
			if(flag)
			break;
		}
	}
	return 0;
}