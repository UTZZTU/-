#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[110][110],maxx=-0x3f3f3f3f3f3f3f3f,n,k;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			f[i][j]=f[i-1][j]+f[i][j-1]+k-f[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int u=i;u<=n;u++)
			{
				for(int v=j;v<=n;v++)
				{
					if(f[u][v]-f[i-1][v]-f[u][j-1]+f[i-1][j-1]>maxx)
					maxx=f[u][v]-f[i-1][v]-f[u][j-1]+f[i-1][j-1];
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}