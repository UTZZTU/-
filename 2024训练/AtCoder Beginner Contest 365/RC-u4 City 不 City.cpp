#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
	int u,v,w,next;
}e[100010];
int n,m,s,t,rd[1010],vis[1010],cnt,head[1010],dis[1010],rdd[1010];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct node
{
	int w,now,pre;
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
void dijstra()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=rdd[i]=0x3f3f3f3f;
	}
	dis[s]=0;
	rdd[s]=0;
	q.push({0,s,-1});
	while(!q.empty())
	{
		auto x=q.top();
		q.pop();
		int u=x.now;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(x.pre==-1)
				{
					rdd[v]=rdd[u];
				}
				else
				{
					rdd[v]=max(rdd[x.pre],rd[u]);
				}
				q.push({dis[v],v,u});
			}
			else if(dis[v]==dis[u]+e[i].w)
			{
				if(x.pre==-1)
				{
					if(rdd[v]>rdd[u])
					{
						rdd[v]=rdd[u];
						q.push({dis[v],v,u});
					}
				}
				else
				{
					if(rdd[v]>max(rdd[x.pre],rd[u]))
					{
						rdd[v]=max(rdd[x.pre],rd[u]);
						q.push({dis[v],v,u});
					}
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
		cin>>rd[i];
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dijstra();
	if(dis[t]>=1000000)
	{
		cout<<"Impossible";
	}
	else cout<<dis[t]<<" "<<rdd[t]<<endl;
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
