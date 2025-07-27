#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[200010],t,n,pos;
signed main ()
{
	pos=5;
	f[1]=1;
	f[2]=4;
	for(int i=3;i<=200000;i++)
	{
		while((3*pos)%(f[i-1]+f[i-2])==0)
		{
			pos++;
		}
		f[i]=pos;
		pos++;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",f[i]);
		}
		printf("\n");
	}
	return 0;
}