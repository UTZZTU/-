#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,f[10010][1010],maxx[10010],g[10010][1010];
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&f[i][j]);
			g[i][j]=f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll mm=0;
		for(int j=1;j<=m;j++)
		{
			if(i==1)
			{
				mm=max(mm,f[i][j]);
				continue;
			}
			f[i][j]=f[i-1][j];
			if(i-k>=1)
			{
				f[i][j]=max(f[i][j],maxx[i-k]+g[i][j]);
			}
			mm=max(mm,f[i][j]);
		}
		maxx[i]=mm;
	}
	cout<<maxx[n];
	return 0;
}