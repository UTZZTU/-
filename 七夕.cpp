#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
const int maxm = 500050;
const int INF = 1234567890;
inline int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
struct Edge
{
	int u,v,w,next;
}e[maxm];
int head[maxn],dis[maxn],vis[maxn],cnt,n,m,s=6,k,res;
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
int main ()
{
	n=read();k=read();m=read();
	for(int i=1,x,y,z;i<=k;i++)
	{
		x=read();y=read();z=1;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1,x,y,z;i<=m;i++)
	{
		x=read();y=read();z=0;
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		res=max(res,dis[i]);
	}
	cout<<res;
	return 0;
}
//priority_queue<int,vector<int>,greater<int>> p;