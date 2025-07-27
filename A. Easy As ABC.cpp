#include <bits/stdc++.h>
using namespace std;
int vis[3][3],dirx[8]={0,0,1,1,1,-1,-1,-1},diry[8]={1,-1,-1,0,1,-1,0,1};
string s[3],u="ZZZ";
bool check(int x,int y)
{
	if(x>=0&&x<3&&y>=0&&y<3&&!vis[x][y]) return true;
	return false;
}
void dfs(int x,int y,string v)
{
	if(v.size()==3)
	{
		u=min(u,v);
		return;
	}
	v+=s[x][y];
	if(v.size()==3)
	{
		u=min(u,v);
		return;
	}
	for(int i=0;i<8;i++)
	{
		int dx=dirx[i]+x,dy=diry[i]+y;
		if(check(dx,dy))
		{
			vis[dx][dy]=1;
			dfs(dx,dy,v);
			vis[dx][dy]=0;
		}
	}
}
void solve()
{
	for(int i=0;i<3;i++) cin>>s[i];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			memset(vis,0,sizeof(vis));
			string v;
			vis[i][j]=1;
			dfs(i,j,v);
		}
	}
	cout<<u;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}