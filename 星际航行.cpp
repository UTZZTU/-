#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct edge{
	int u,v,w,next;
}e[N];
int head[N],dis[N],cnt,vis[N],s=1,n,f[N],k;
deque<int> q;
void updata()
{
	if(q.empty()) return;
	else
	{
		if(dis[q.front()]>dis[q.back()])
		swap(q.front(),q.back());
	}
}
void add(int u,int v,int w)
{
	e[cnt++].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void spfa()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=0x3f3f3f3f;
	}
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
	memset(f,-1,sizeof f);
	scanf("%d",&n);
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(f[k]>0&&f[k]!=i-1)
		{
			add(f[k],i,1);
//			add(i,f[k],1);
//			printf("1");
		}
		if(i>=2)
		{
			add(i-1,i,1);
			add(i,i-1,1);
		}
		f[k]=i;
	}
	spfa();
	printf("%d",dis[n]);
	return 0;
}