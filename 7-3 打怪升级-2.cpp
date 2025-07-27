#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 400010
#define INF 0x3f3f3f3f
ll n,m,k,f[1010][1010],b1,b2,nl,val,b,minn=0x3f3f3f3f,mb,pre[1010];
struct Edge
{
	int u,v,w,ww,next;
}e[maxn];
int head[maxn],dis[maxn],vis[maxn],cnt,s,dis2[maxn];
struct node
{
	int w,now;
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
inline void add(int u,int v,int w,int ww)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].ww=ww;
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
				dis2[v]=dis2[u]+e[i].ww;
				pre[v]=u;
				q.push((node){dis[v],v});
			}
			else if((dis[v]==dis[u]+e[i].w)&&(dis2[v]<dis2[u]+e[i].ww))
			{
				dis2[v]=dis2[u]+e[i].ww;
				pre[v]=u;
				q.push((node){dis[v],v});
			}
//			printf("dis2:   %lld\n",dis2[v]);
		}
	}
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) pre[i]=i;
	memset(f,0x3f3f3f3f,sizeof f);
	while(m--)
	{
		scanf("%lld%lld%lld%lld",&b1,&b2,&nl,&val);
		f[b1][b2]=f[b2][b1]=nl;
		add(b1,b2,nl,val);
		add(b2,b1,nl,val);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(k==i||k==j||i==j||f[i][k]==0x3f3f3f3f||f[k][j]==0x3f3f3f3f) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll maxx=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			maxx=max(maxx,f[i][j]);
		}
		if(maxx<minn)
		{
			b=i;
			minn=maxx;
		}
	}
	printf("%lld\n",b);
	s=b;
	scanf("%lld",&k);
	dijkstra();
	while(k--)
	{
		scanf("%lld",&mb);
		if(mb==b) printf("%d\n0 0\n",b);
		else
		{
			vector<int> vec;
			int x=mb;
			while(pre[x]!=x)
			{
				vec.push_back(x);
				x=pre[x];
			}
			printf("%lld",b);
			for(int i=vec.size()-1;i>=0;i--)
			{
				printf("->%d",vec[i]);
			}
			printf("\n");
			printf("%lld %lld\n",dis[mb],dis2[mb]);
		}
	}
	return 0;
}