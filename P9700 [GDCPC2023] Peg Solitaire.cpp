#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,f[10][10],minn,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void dfs(int row,int col,int k)
{
	minn=min(minn,k);
	if(row>n) return;
	if(f[row][col])
	{
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+row,yy=dy[i]+col;
			int xxx=dx[i]+xx,yyy=dy[i]+yy;
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&xxx>=1&&xxx<=n&&yyy>=1&&yyy<=m&&f[xx][yy]&&!f[xxx][yyy])
			{
				f[row][col]=0;
				f[xx][yy]=0;
				f[xxx][yyy]=1;
				dfs(1,1,k-1);
				f[row][col]=1;
				f[xx][yy]=1;
				f[xxx][yyy]=0;
			}
		}
	}
	if(col+1==m+1)
	{
		dfs(row+1,1,k);
	}
	else
	dfs(row,col+1,k);
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(f,0,sizeof f);
		minn=100;
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			f[x][y]=1;
		}
		dfs(1,1,k);
		printf("%d\n",minn);
	}
	return 0;
}