#include<bits/stdc++.h>
using namespace std;
const int maxn =200020;
const int maxm =500050;
const int inf = 1234567890;
inline int read()
{
	int x,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
int vis[maxn],dis[maxn],head[maxn],cnt,n,m,s;
struct edge
{
	int u,v,w,next;
}e[maxm];
inline void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
deque<int> q;
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
void spfa()
{
	for(int i=1;i<=n;i++)
	dis[i]=inf;
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
		if(dis[i]==inf)
		cout<<"2147483647";
		else
		cout<<dis[i];
	}
	return 0;
 } 
