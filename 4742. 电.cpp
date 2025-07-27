#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int t,e[N],ne[N],idx,h[N],n,a[N],x,y,vis[N],maxx;
void add(int x,int y)
{
	e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
int dfs(int u)
{
	if(vis[u]!=-1) return vis[u];
	vis[u]=1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(a[u]>a[j]) vis[u]+=dfs(j);
	}
	return vis[u];
}
int main  ()
{
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		memset(h,-1,sizeof(h));
		memset(vis,-1,sizeof(vis));
		maxx=idx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&x,&y);
			if(a[x]>a[y]) add(x,y);
			else if(a[y]>a[x]) add(y,x);
		}
		for(int i=1;i<=n;i++)
		{
			int m=dfs(i);
			maxx=max(maxx,m);
		}
		printf("Case #%d: %d\n",j,maxx);
	}
	return 0;
}