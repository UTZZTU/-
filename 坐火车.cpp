#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
const int maxm = 500050;
const int INF = 1234567890;
struct Edge
{
	int u,v,w,next;
}e[maxm];
int head[maxn],dis[maxn],vis[maxn],cnt,n,m,s=1,num[maxn];
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
	dis[i]=num[i]=INF;
	dis[s]=0;
	num[s]=1;
	q.push((node){1,s});
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
			if(num[v]>num[u]+1){
				num[v]=num[u]+1;
				dis[v]=dis[u]+e[i].w;
				q.push((node){num[v],v});
			}
			else if(num[v]==num[u]+1){
				if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push((node){num[v],v});
			}
			}
		}
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	cout<<num[n]<<" "<<dis[n];
	return 0;
}