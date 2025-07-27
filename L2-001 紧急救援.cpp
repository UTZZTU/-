#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node{
	int u,v,w,next;
}e[100010];
struct line{
	int w,now;
	inline bool operator<(const line &x) const
	{
		return w>x.w;
	}
};
priority_queue<line> p;
int n,m,s,d,dist[10100],pre[10100],vis[1010],cnt,head[10010],num[10100],ff[10100],tt[10100];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijstra()
{
	for(int i=0;i<n;i++)
	dist[i]=inf;
	dist[s]=0;
	tt[s]=1;
	ff[s]=num[s];
	p.push({0,s});
	while(!p.empty())
	{
		line x=p.top();
		p.pop();
		int u=x.now;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dist[v]>dist[u]+e[i].w)
			{
				dist[v]=dist[u]+e[i].w;
				ff[v]=ff[u]+num[v];
				pre[v]=u;
				tt[v]=tt[u];
				p.push({dist[v],v});
			}
			else if(dist[v]==dist[u]+e[i].w)
			{
				tt[v]+=tt[u];
				if(ff[v]<ff[u]+num[v])
				{
					ff[v]=ff[u]+num[v];
					pre[v]=u;
				}
			}
		}
	}
}
int main ()
{
	cin>>n>>m>>s>>d;
	for(int i=1;i<=500;i++)
	{
		pre[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dijstra();
	cout<<tt[d]<<" "<<ff[d]<<endl;
	vector<int> vec;
	while(d!=pre[d])
	{
		vec.push_back(d);
		d=pre[d];
	}
	vec.push_back(d);
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(i) cout<<vec[i]<<" ";
		else cout<<vec[i];
	}
	return 0;
}