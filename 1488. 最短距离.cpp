#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
struct line{
	int u,v,w,next;
}e[N];
int head[N],dist[N],cnt,vis[N],n,m,k,qq;
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
	int w,now;
	inline bool operator<(const node &x) const{
		return w>x.w;
	}
};
priority_queue<node> q;
void dijstra()
{
	for(int i=1;i<=n;i++)
	dist[i]=0x3f3f3f3f;
	q.push({0,0});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		int u=x.now;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dist[v]>dist[u]+e[i].w)
			{
				dist[v]=dist[u]+e[i].w;
				q.push({dist[v],v});
			}
		}
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	scanf("%d",&k);
	while(k--)
	{
		int x;
		scanf("%d",&x);
		add(0,x,0);
		add(x,0,0);
	}
	dijstra();
	scanf("%d",&qq);
	while(qq--)
	{
		int yk;
		scanf("%d",&yk);
		printf("%d\n",dist[yk]);
	}
	return 0;
}