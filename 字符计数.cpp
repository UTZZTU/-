#include <bits/stdc++.h>
using namespace std;
int vis[1010][1010],cnt,n,m,num1,num2,num3,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0};
string a[1010];
void dfs(int x,int y)
{
	if(a[x][y]=='.')
	{
		if(!(x-1<0||x+1>=n||y-1<0||y+1>=m)&&a[x-1][y]=='#'&&a[x+1][y]=='#'&&a[x][y-1]=='#'&&a[x][y+1]=='#')
		cnt++;
		return;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			int dx=dirx[i]+x,dy=diry[i]+y;
			if(dx<0||dx>=n||dy<0||dy>=m||vis[dx][dy])
			continue;
			vis[dx][dy]=1;
			dfs(dx,dy);
		}
	}
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j]||a[i][j]=='.')
			continue;
			cnt=0;
			vis[i][j]=1;
			dfs(i,j);
			if(!cnt)
			num1++;
			else if(cnt==1)
			num2++;
			else if(cnt==2)
			num3++;
		}
	}
	cout<<num1<<" "<<num2<<" "<<num3;
	return 0;
}