#include <bits/stdc++.h>
using namespace std;
vector<int> vec1[1010],vec2[1010];
int n,m,x,y,f[1010],vis1[1010],vis2[1010];
int dfs1(int x)
{
	int res=1;
	for(int i=0;i<vec1[x].size();i++)
	{
		if(vis1[vec1[x][i]])
		continue;
		vis1[vec1[x][i]]=1;
		res+=dfs1(vec1[x][i]);
	}
	return res;
}
int dfs2(int x)
{
	int res=1;
	for(int i=0;i<vec2[x].size();i++)
	{
		if(vis2[vec2[x][i]])
		continue;
		vis2[vec2[x][i]]=1;
		res+=dfs2(vec2[x][i]);
	}
	return res;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		vec1[x].push_back(y);
		vec2[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		vis1[i]=vis2[i]=1;
		int pre=dfs1(i),post=dfs2(i);
		if(pre+post==n+1)
		{
			f[post]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		cout<<f[i]<<" ";
		else
		cout<<-1<<" ";
	}
	return 0;
}