#include <bits/stdc++.h>
using namespace std;
int t,n,m,f[1010][1010],vis[1010][1010],maxx,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0};
bool check(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m&&f[x][y]>0&&!vis[x][y]) return true;
	return false;
}
int dfs(int x,int y)
{
	int res=f[x][y];
	for(int i=0;i<4;i++)
	{
		int xx=x+dirx[i],yy=y+diry[i];
		if(check(xx,yy))
		{
			vis[xx][yy]=1;
			res+=dfs(xx,yy);
		}
	}
	return res;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&f[i][j]);
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[i][j]>0&&!vis[i][j])
				{
					vis[i][j]=1;
					maxx=max(maxx,dfs(i,j));
				}
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}