#include <bits/stdc++.h>
using namespace std;
int n,f[55],g[55][55],x,y,flag;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*(n-1)/2-1;i++)
	{
		cin>>x>>y;
		f[x]++;
		g[x][y]=g[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(!g[i][j]&&!g[j][i])
			{
				x=i,y=j;
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	if(f[x]>=f[y]) cout<<x<<" "<<y<<endl;
	else cout<<y<<" "<<x<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}