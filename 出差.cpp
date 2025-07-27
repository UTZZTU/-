#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int mn=9999999;
int visit[1010];
int time[1010];
int n,m;
struct edge
{
	int from;
	int to;
	int time;
	edge(int a,int b,int c):from(a),to(b),time(c){};
};
vector<edge> e[1010];
void dfs(int x,int t)
{
	if(x==n)
	{
		mn=min(mn,t);
		return;
	}
	for(int i=0;i<e[x].size();i++)
	{
		int j=e[x][i].to;
		if(visit[j])
		continue;
		visit[j]=1;
		if(j==n)
		dfs(j,t+e[x][i].time);
		else
		dfs(j,t+e[x][i].time+time[j]);
		visit[j]=0;
	}
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&time[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({u,v,w});
		e[v].push_back({v,u,w});
	}
	dfs(1,0);
	cout<<mn;
	return 0;
}