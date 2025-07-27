#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010,M=N*2;
int w[N];
int head[N],idx,e[M],wt[M],ne[M];
ll dist[N][N];
bool vis[N][N];
void add(int u,int v,int wi)
{
	e[idx]=v,wt[idx]=wi,ne[idx]=head[u],head[u]=idx++;
}
void solve()
{
	idx=0;
	memset(head,-1,sizeof head);
	int n,m;
	cin>>n>>m;
	int u,v,wi;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>wi;
		add(u,v,wi);
		add(v,u,wi);
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(dist,0x3f,sizeof dist);
	dist[1][1]=0;
	priority_queue<tuple<ll,int,int>> pq;
	pq.push(make_tuple(0,1,1));
	memset(vis,0,sizeof vis);
	while(!pq.empty())
	{
		int x=get<1>(pq.top()),y=get<2>(pq.top());
		pq.pop();
		if(vis[x][y]) continue;
		vis[x][y]=true;
		for(int i=head[x];~i;i=ne[i])
		{
			if(dist[e[i]][y]>dist[x][y]+w[y]*wt[i])
			{
				dist[e[i]][y]=dist[x][y]+w[y]*wt[i];
				pq.push(make_tuple(-dist[e[i]][y],e[i],y));
			}
			if(dist[e[i]][x]>dist[x][y]+w[x]*wt[i])
			{
				dist[e[i]][x]=dist[x][y]+w[x]*wt[i];
				pq.push(make_tuple(-dist[e[i]][x],e[i],x));
			}
		}
	}
	int minn=1e18;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,dist[n][i]);
	}
	cout<<minn<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}