#include <iostream>
using namespace std;
char room[55][55];
int flag=0,n,m,visit[55][55],dir[4][2]={1,0,0,1,-1,0,0,-1},dx,dy;
int check(int a,int b)
{
	if(a>=1&&a<=n&&b>=1&&b<=m)
	return 1;
	else
	return 0;
}
void dfs(int a,int b)
{
	visit[a][b]=1;
	if(flag)
	return;
	for(int i=0;i<4;i++)
	{
		int newx=a+dir[i][0];
		int newy=b+dir[i][1];
		if(check(newx,newy)&&room[newx][newy]==room[a][b])
	{
		if(visit[newx][newy]==1&&newx!=dx&&newy!=dy)
		{
			flag=1;
			return;
		}
		else if(visit[newx][newy]==0)
		{
			visit[newx][newy]=1;
			dx=a;
			dy=b;
			dfs(newx,newy);
			dx=a;
			dy=b;
		}
	}
	}
}
int main ()
{
	int i,j;
	cin>>n>>m;
	getchar();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		cin>>room[i][j];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			memset(visit,0,sizeof(visit));
			dfs(i,j);
			if(flag==1)
			break;
		}
		if(flag==1)
		break;
	}
	if(flag==1)
	printf("Yes");
	else
	printf("no");
	return 0;
}