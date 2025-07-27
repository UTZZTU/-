#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,maxx,a[10];
int f[110][10];
void dfs(int level)
{
	if(level==n+1)
	{
		int res=0;
		for(int i=1;i<=m;i++)
		{
			if(f[i][3]==0)
			{
				if(f[i][4]*a[f[i][1]]+f[i][5]*a[f[i][2]]<=f[i][6])
				{
					res+=f[i][7];
				}
			}
			else
			{
				if(f[i][4]*a[f[i][1]]+f[i][5]*a[f[i][2]]>=f[i][6])
				{
					res+=f[i][7];
				}
			}
		}
		maxx=max(maxx,res);
		return;
	}
	for(int i=0;i<=k;i++)
	{
		a[level]=i;
		dfs(level+1);
	}
}
signed main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=7;j++)
		{
			cin>>f[i][j];
		}
	}
	dfs(1);
	cout<<maxx;
	return 0;
}