#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
#define inf 1234567890
#define maxn 200020
#define maxm 500050
il int read()
{
	int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
struct Edge
{
	int u,v,w,next;
}e[maxm];
int head[maxn],dis[maxn],vis[maxn],cnt,n,m,tot,sum;
il void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
typedef pair <int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>>q;
il void prim()
{
	for(re int i=2;i<=n;i++)
	dis[i]=inf;
	q.push(make_pair(0,1));
	while(!q.empty()&&tot<n)
	{
		int x=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])
		continue;
		vis[u]=1;
		tot++;
		sum+=x;
		for(re int i=head[u],v;i;i=e[i].next)
		{
			v=e[i].v;
			if(dis[v]>e[i].w)
			{
				dis[v]=e[i].w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main ()
{
	n=read();m=read();
	for(re int i=1,u,v,w;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	prim();
	if(tot==n)
	printf("%d",sum);
	else
	printf("orz");
	return 0;
}