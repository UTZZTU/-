#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
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
deque<int> q;
int vis[maxn],head[maxn],dis[maxn],cnt,n,m,s;
void update()
{
	if(q.empty())
	return;
	else
	{
		if(dis[q.front()]>dis[q.back()])
		swap(q.front(),q.back());
	}
}
inline void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void spfa()
{
	for(int i=1;i<=n;i++)
	dis[i]=INF;
	dis[s]=0;
	vis[s]=1;
	q.push_back(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next)
		{
			update();
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					if(q.size()&&dis[v]<dis[q.front()])
					q.push_front(v);
					else
					q.push_back(v);
				}
			}
		}
	}
}
int main ()
{
	n=read();m=read();s=read();
	for(int i=1,x,y,z;i<=m;i++)
	{
		x=read();y=read();z=read();
		add(x,y,z);
	}
	spfa();
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		cout<<" ";
		if(dis[i]==INF)
		cout<<"2147483647";
		else
		cout<<dis[i];
	}
	return 0;
}