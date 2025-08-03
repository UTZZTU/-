#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1234567890
mt19937_64 mrand(random_device{}()); 
int n,m,s,t,head[10010],cnt,dis[10010],vis[10010],fire[10010],ff[10010];
struct node
{
	int w,now,ff;
	inline bool operator<(const node &x) const
	{
		if(w!=x.w)
		return w>x.w;
		else return ff>x.ff;
	}
};
struct Edge
{
	int u,v,w,next;
}e[10010];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<node> q;
void dijstra()
{
	for(int i=1;i<=n;i++) dis[i]=ff[i]=INF;
	dis[s]=0;
	ff[s]=0;
	q.push({0,s,0});
	while(!q.empty())
	{
		node xx=q.top();
		int u=xx.now;
//		node u=q.top();
		q.pop();
//		if(vis[u]) continue;
//		if()
//		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
//				if(xx.ff==-1)
//				{
//					ff[v]=0;
//					q.push({dis[v],v,fire[v]});
//				}
//				else
//				{
//					ff[v]=max(ff[v],xx.ff);
//					q.push({dis[v],v,ff[v]});
//				}
				ff[v]=xx.ff;
				q.push({dis[v],v,max(fire[v],ff[v])});
			}
			else if(dis[v]==dis[u]+e[i].w)
			{
				if(ff[v]>xx.ff)
				{
					ff[v]=xx.ff;
					q.push({dis[v],v,max(fire[v],ff[v])});
				}
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>fire[i];
//		ff[i]=fire[i];
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dijstra();
	if(dis[t]==INF) cout<<"Impossible";
	else cout<<dis[t]<<" "<<ff[t];
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}