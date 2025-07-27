#include <bits/stdc++.h>
using namespace std;
int n,m,f[1010][1010],g[1010][1010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			g[int(ceil(i/2.0))][int(ceil(j/2.0))]+=f[i][j];
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=m/2;j++)
		{
			printf("%d ",g[i][j]/4);
		}
		printf("\n");
	}
	return 0;
}