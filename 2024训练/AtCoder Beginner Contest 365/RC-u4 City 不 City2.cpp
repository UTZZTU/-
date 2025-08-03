#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
	int u,v,w,next;
}e[100010];
int n,m,s,t,rd[1010],vis[1010],cnt,head[1010],dis[1010],pp;
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
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
void dijstra(int xz)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		auto x=q.top();
		q.pop();
		int u=x.now;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(rd[v]>xz&&v!=t) continue;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
bool check(int x)
{
	dijstra(x);
	if(dis[t]==pp)
	{
		return true;
	}
	else return false;
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>rd[i];
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dijstra(100);
	pp=dis[t];
	if(pp>=10000000)
	{
		cout<<"Impossible";
		return;
	}
	int l=0,r=100;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<pp<<" "<<l<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
