#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> e[maxn];
int vis[maxn];
inline int read()
{
	int x=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*k;
}
int n,m;
void dfs(int x,int k)
{
	if(vis[x])
	return;
	vis[x]=k;
	for(int i=0;i<e[x].size();i++)
	{
		dfs(e[x][i],k);
	}
}
int main ()
{
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++)
	{
		u=read();v=read();
		e[v].push_back(u);
	}
	for(int i=n;i>=1;i--) dfs(i,i);
	for(int i=1;i<n;i++)
	{
		printf("%d ",vis[i]);
	}
	printf("%d",n);
	return 0;
}