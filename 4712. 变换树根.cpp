#include <bits/stdc++.h>
using namespace std;
int n,r1,r2,pre[50010],k,vis[500010];
vector<int> e[50010];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		if(vis[e[x][i]])
		continue;
		pre[e[x][i]]=x;
		dfs(e[x][i]);
	}
}
int main ()
{
	scanf("%d%d%d",&n,&r1,&r2);
	for(int i=1;i<=n;i++)
	{
		if(i==r1)
		continue;
		scanf("%d",&k);
		e[k].push_back(i);
		e[i].push_back(k);
	}
	dfs(r2);
	for(int i=1;i<=n;i++)
	{
		if(i==r2)
		continue;
		cout<<pre[i]<<" ";
	}
	return 0;
}