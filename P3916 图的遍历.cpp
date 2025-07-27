#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> e[maxn];
int n,m,mx;
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
void dfs(int x)
{
	if(x>mx)
	mx=x;
	if(mx==n)
	return;
	if(e[x].size()==0)
	return;
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i];
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v);
			vis[v]=0;
		}
	}
}
int main ()
{
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++)
	{
		u=read();v=read();
		e[u].push_back(v);
	}
	for(int i=1;i<n;i++)
	{
		if(i!=1)
		printf(" ");
		mx=0;
		vis[i]=1;
		dfs(i);
		vis[i]=0;
		printf("%d",mx);
	}
	printf(" %d",n);
	return 0;
}