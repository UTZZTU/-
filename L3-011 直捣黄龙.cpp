#include <bits/stdc++.h>
using namespace std;
const int INF = 1234567890;
int n,m,s,d,pre[1550000],dis[1550000],vis[1550000],cnt,head[1550000],a[1550000],num[1550000],way[1550000],jf[1550000];
map<string,int> mp1;
map<int,string> mp2;
string dh1,dh2;
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
		cout<<dh1;
		return;
	}
	else
	{
		print(pre[x]);
		cout<<"->"<<mp2[x];
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
				jf[v]=jf[u]+1;
				pre[v]=u;
			}
			else if(dis[v]==dis[u]+e[i].w)
			{
				way[v]+=way[u];
				if(jf[v]<jf[u]+1)
				{
					jf[v]=jf[u]+1;
					num[v]=num[u]+a[v];
					pre[v]=u;
				}
				else if(jf[v]==jf[u]+1)
				{
					if(num[v]<num[u]+a[v])
					{
						num[v]=num[u]+a[v];
					    pre[v]=u;
					}
				}
			}
		}
	}
}
int main ()
{
	cin>>n>>m>>dh1>>dh2;
	for(int i=1;i<n;i++)
	{
		string u;
		int v;
		cin>>u>>v;
		mp1[u]=i;
		mp2[i]=u;
		a[i]=v;
	}
	d=mp1[dh2];
	jf[s]=1;
	way[s]=1;
	for(int i=1,z;i<=m;i++)
	{
		string x,y;
		cin>>x>>y>>z;
		add(mp1[x],mp1[y],z);
		add(mp1[y],mp1[x],z);
	}
	dijkstra();
	print(d);
	cout<<endl;
	cout<<way[d]<<" "<<dis[d]<<" "<<num[d];
	return 0;
}