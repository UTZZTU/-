#include <bits/stdc++.h>
using namespace std;
int m,n,f[1010][1010],vis[1010][1010],judge,flag;
vector<pair<int,int>> vec[1000100];
bool check(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=n&&!vis[x][y]) return true;
	return false;
}
void bfs()
{
	queue<pair<int,int>> q;
	q.push({1,1});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int x=p.first,y=p.second;
		if(vis[x][y]) continue;
		vis[x][y]=1;
		if(x==m&&y==n)
		{
			judge=1;
			return;
		}
		for(int i=0;i<vec[f[x][y]].size();i++)
		{
			pair<int,int> pp=vec[f[x][y]][i];
			if(vis[pp.first][pp.second]) continue;
			if(pp.first==m&&pp.second==n)
			{
				judge=1;
				return;
			}
			q.push(pp);
		}
	}
}
int main ()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
			if(f[i][j]==n*m) flag=1;
		}
	}
	if(!flag)
	{
		puts("no");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vec[i*j].push_back({i,j});
		}
	}
	bfs();
	if(judge) puts("yes");
	else puts("no");
	return 0;
}