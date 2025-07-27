#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200050;
const int maxm = 500050;
const int INF = 1e16;
struct Edge
{
	int u,v,w,next;
}e[maxm];
int head[maxn],dis[maxn],vis[maxn],cnt,n,s=1;
struct node
{
	int w,now;
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
inline void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijkstra()
{
	for(int i=1;i<=n;i++)
	dis[i]=INF;
	dis[s]=0;
	q.push((node){0,s});
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
			}
		}
	}
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int a,b,x;
		scanf("%lld%lld%lld",&a,&b,&x);
		add(i,i+1,a);
		add(i,x,b);
	}
	dijkstra();
	printf("%lld",dis[n]);
	return 0;
}
//priority_queue<int,vector<int>,greater<int>> p;