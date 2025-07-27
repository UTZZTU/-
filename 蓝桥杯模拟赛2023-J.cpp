#include <bits/stdc++.h>
using namespace std;
int n,m,f[110][110],vis[110][110],maxx,cnt[110][110],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int dfs(int x,int y)
{
	int uu=1,tt=0;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&f[xx][yy]<f[x][y])
		{
			if(vis[xx][yy])
			{
				tt=max(tt,cnt[xx][yy]);
			}
			else
			{
				tt=max(tt,dfs(xx,yy));
			}
		}
	}
	cnt[x][y]=uu+tt;
	return cnt[x][y];
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				maxx=max(maxx,dfs(i,j));
			}
		}
	}
	printf("%d",maxx);
	return 0;
}
//蓝桥杯模拟赛2023-A