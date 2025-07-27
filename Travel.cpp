#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define il inline
ll head[500010],vis[500010],dis[500010],cnt,s,n,m,vec[500010],k,pre[500010];
struct edge
{
	int u,v,w,next;
}e[500010];
map<pair<int,int>,int> mp;
struct node
{
	ll w,now;
	il bool operator <(const node &x) const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
il void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijkstra()
{
	for(int i=2;i<=n;i++)
	dis[i]=INF;
	q.push((node){0,1});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		int u=x.now;
		if(vis[u])
		continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push((node){dis[v],v});
				pre[v]=u;
			}
		}
	}
}
int main ()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	pre[i]=i;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		if(!mp.count({x,y}))
		{
			mp[{x,y}]=z;
			mp[{y,x}]=z;
		}
		else
		{
			mp[{x,y}]=min(mp[{x,y}],z);
			mp[{y,x}]=min(mp[{y,x}],z);
		}
	}
	dijkstra();
	sort(vec+1,vec+k+1);
	int x=n;
	while(pre[x]!=x)
	{
		vec[++k]=mp[{x,pre[x]}];
		x=pre[x];
	}
	sort(vec+1,vec+1+k);
	for(int i=k;i>=1&&s>=1;i--,s--)
	{
		dis[n]-=vec[i];
	}
	if(dis[n]==INF)
	dis[n]=0;
	cout<<dis[n];
	return 0;
}