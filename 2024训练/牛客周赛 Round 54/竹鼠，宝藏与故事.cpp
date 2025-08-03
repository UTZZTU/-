#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,f[1010][1010],dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},vis[1010][1010],yes[1010][1010];
ll res;
void dfs(int x,int y,vector<pair<int,int>> vec)
{
//	cout<<x<<" "<<y<<endl;
	if(x==n&&y==m)
	{
		for(auto [u,v]:vec)
		{
			yes[u][v]=1;
		}
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=dirx[i]+x,yy=diry[i]+y;
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&f[xx][yy]!=-1&&!vis[xx][yy])
		{
			vis[xx][yy]=1;
			vec.push_back({xx,yy});
			dfs(xx,yy,vec);
			vec.pop_back();
			vis[xx][yy]=0;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	vis[1][1]=1;
	vector<pair<int,int>> vec;
	vec.push_back({1,1});
	dfs(1,1,vec);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(yes[i][j])
			{
				res+=f[i][j];
			}
		}
	}
	cout<<res;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}