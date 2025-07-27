#include <bits/stdc++.h>
using namespace std;
int n,m,dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1},maxn;
map<string,int> mp;
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	return true;
	else
	return false;
}
string a[55];
void dfs(int x,int y,string v,int i)
{
	v+=a[x][y];
	if(v.size()==3)
	{
		if(v[1]==v[2]&&v[1]!=v[0])
		{
			mp[v]++;
		}
		return;
	}
	int dx=x+dir[i][0],dy=y+dir[i][1];
	if(check(dx,dy))
	dfs(dx,dy,v,i);
	else
	return;
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	getline(cin,a[i]);
	if(n==1||m==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			string u;
			u.clear();
			dfs(i,j,u,0);
			u.clear();
			dfs(i,j,u,1);
			u.clear();
			dfs(i,j,u,2);
			u.clear();
			dfs(i,j,u,3);
			u.clear();
			dfs(i,j,u,4);
			u.clear();
			dfs(i,j,u,5);
			u.clear();
			dfs(i,j,u,6);
			u.clear();
			dfs(i,j,u,7);
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		maxn=max(maxn,it->second);
	}
	cout<<maxn;
	return 0;
}