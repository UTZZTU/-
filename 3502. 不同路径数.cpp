#include <bits/stdc++.h>
using namespace std;
set<string> st;
int n,m,k,f[10][10],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y,string u)
{
	u+=f[x][y]+'0';
	if(u.size()==k+1)
	{
		st.insert(u);
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		dfs(xx,yy,u);
	}
}
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			string s;
			dfs(i,j,s);
		}
	}
	cout<<st.size();
	return 0;
}