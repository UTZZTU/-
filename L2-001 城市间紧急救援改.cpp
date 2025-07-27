#include <bits/stdc++.h>
using namespace std;
const int INF = 1234567890;
int n,m,s,d,pre[1550000],dis[1550000],vis[1550000],cnt,head[1550000],a[1550000],num[1550000],way[1550000];
struct node
{
	int w,now;
	inline bool operator <(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
struct edge
{
	int u,v,w,next;
}e[1200020];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void print(int x)
{
	if(x==s)
	{
		printf("%d",x);
		return;
	}
	else
	{
		print(pre[x]);
		printf(" %d",x);
	}
}
void dijkstra()
{
	for(int i=0;i<n;i++)
	{
		dis[i]=INF;
	}
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
				way[v]=way[u];
				num[v]=num[u]+a[v];
				pre[v]=u;
			}
			else if(dis[v]==dis[u]+e[i].w)
			{
				way[v]+=way[u];
				if(num[v]<num[u]+a[v])
				{
					num[v]=num[u]+a[v];
					pre[v]=u;
				}	
			}
		}
	}
}
int main ()
{
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	num[s]=a[s];
	way[s]=1;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	cout<<way[d]<<" "<<num[d]<<endl;
	print(d);
	return 0;
}