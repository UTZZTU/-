//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
const int N = 2e5+10;
const int M =2e6+10;
int head[N],cnt,head1[N],cnt1;
map<int,map<int,int> > mp;
int dfn[N],low[N],id,sta[N],top,color[N],cl;
bool vis[N];
int dp[N][2];
int n,m,ans;
struct node
{
	int to,nxt;bool use;
}g[M],g1[M];
inline void Init()
{
	mp.clear();
	ans=cnt=top=id=cl=0;
	for(int i=1;i<=n;i++)
		head[i]=head1[i]=-1,vis[i]=dfn[i]=dp[i][1]=dp[i][0]=0;
	return ;	
}
inline void add(int u,int v)
{
	g[cnt].to=v; g[cnt].use=0; g[cnt].nxt=head[u]; head[u]=cnt++;	
} 
inline void add1(int u,int v)
{
	g1[cnt1].to=v; g1[cnt1].nxt=head1[u]; head1[u]=cnt1++;	
} 
inline void tarjan(int u)
{
	int v;
	low[u]=dfn[u]=++id; sta[++top]=u; vis[u]=1;
	for(int i=head[u];i!=-1;i=g[i].nxt)
	{
		if(g[i].use) continue;
		g[i].use=g[i^1].use=1;
		v=g[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(vis[u])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		color[u]=++cl;
		while(sta[top]!=u)
		{
			color[sta[top]]=cl; vis[sta[top--]]=0;
		}
		vis[sta[top--]]=0;
	}
	return ;	
}
inline void build()
{
	int u,v;
	for(u=1;u<=n;u++)
		for(int i=head[u];i!=-1;i=g[i].nxt)
		{
			v=g[i].to;
			if(color[u]==color[v]||mp[color[u]][color[v]]) continue;
			mp[color[u]][color[v]]=mp[color[v]][color[u]]=1;
			add1(color[u],color[v]); add1(color[v],color[u]);
			//cout<<color[u]<<" "<<color[v]<<endl;
		}
}
inline void dfs(int u,int fa)
{
	int v;
	for(int i=head1[u];i!=-1;i=g1[i].nxt)
	{
		v=g1[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(dp[u][0]<dp[v][0]+1)
		{
			dp[u][1]=dp[u][0];
			dp[u][0]=dp[v][0]+1;
		}
		else if(dp[u][0]==dp[v][0]+1)
		{
			if(dp[u][1]<dp[u][0])
				dp[u][1]=dp[u][0];
		}
		else 
		{
			if(dp[u][1]<dp[v][0]+1)
				dp[u][1]=dp[v][0]+1;
		}		
	}
	ans=max(ans,dp[u][0]+dp[u][1]);
	return ;
}
int main(void)
{
	int u,v;
	while(~scanf("%d%d",&n,&m)&&(n||m))
	{
		Init();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
		}
		tarjan(1);
		build();
		dfs(1,0);
		printf("%d\n",cl-1-ans);
	}	
	return 0;	
} 