#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[2010][2010],maxx=-1e18,k,n,m,r,c;
int main ()
{
	scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			f[i][j]=f[i-1][j]+f[i][j-1]+k-f[i-1][j-1];
		}
	}
	for(int i=r;i<=n;i++)
	{
		for(int j=c;j<=m;j++)
		{
			maxx=max(maxx,f[i][j]-f[i-r][j]-f[i][j-c]+f[i-r][j-c]);
		}
	}
	cout<<maxx;
	return 0;
}