#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,f[1010][1010],maxx;
signed main ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		maxx=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				scanf("%lld",&f[j][k]);
				f[j][k]+=f[j-1][k-1];
			}
		}
		for(int j=1;j<=n;j++)
		{
			maxx=max(maxx,max(f[n][j],f[j][n]));
		}
		printf("Case #%lld: %lld\n",i,maxx);
	}
	return 0;
}