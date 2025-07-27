#include <iostream>
using namespace std;
int ans,a[110][110],s[110][110],n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int i,int j)
{
	if(s[i][j])
	return s[i][j];
	s[i][j]=1;
	for(int w=0;w<4;w++)
	{
		int xx=i+dx[w];
		int yy=j+dy[w];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]<a[i][j])
		{
			dfs(xx,yy);
			s[i][j]=max(s[i][j],s[xx][yy]+1);
		}
	}
	return s[i][j];
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		ans=max(ans,dfs(i,j));
	}
	printf("%d",ans);
	return 0;
}