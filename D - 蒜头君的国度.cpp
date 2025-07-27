#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
int head[100010],cnt,dis[100010],vis[100010],s,n,m,father[100010];
struct Edge
{
	int u,v,w,next;
}e[100010];
struct node
{
	int w,now;
	il bool operator <(const node &x) const
	{
		return w>x.w;
	}
};
priority_queue<node> p;
il void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijstra()
{
	for(int i=1;i<=n;i++)
	dis[i]=0x3f3f3f3f;
	dis[s]=0;
	p.push({0,s});
	while(!p.empty())
	{
		node x=p.top();
		p.pop();
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
				father[v]=u;
				p.push({dis[v],v});
			}
		}
	}
}
int main ()
{
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&s);
	    for(int i=1;i<=n;i++)
	    father[i]=i;
	    cnt=0;
	    memset(vis,0,sizeof(vis));
	    memset(head,0,sizeof(head));
	for(int i=1,u,v,w;i<=n-1;i++)
	{
		scanf("%d %d",&u,&v);
		w=1;
		add(u,v,w);
		add(v,u,w);
	}
	dijstra();
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		cout<<" ";
		if(i==s)
		cout<<-1;
		else
		cout<<father[i];
	}
	cout<<endl;
	}
	return 0;
}