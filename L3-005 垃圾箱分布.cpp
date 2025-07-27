#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
const int maxm = 500050;
const int inf = 1234567890;
#define il inline
struct edge
{
	int u,v,w,next;
}e[maxm];
int head[maxn],vis[maxn],dis[maxn],cnt,n,m,k,ds,s;
struct node
{
	int w,now;
	il bool operator<(const node &x )const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
il void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dijkstra()
{
	for(int i=1;i<=n+m;i++)
	dis[i]=inf;
	dis[s]=0;
	q.push((node{0,s}));
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
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	string a,b;
	int d;
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b>>d;
		int x,y;
		if(a[0]=='G')
		x=stoi(a.substr(1))+n;
		else
		x=stoi(a);
		if(b[0]=='G')
		y=stoi(b.substr(1))+n;
		else
		y=stoi(b);
		add(x,y,d);
		add(y,x,d);
	}
	int mb=0;
	double zdjl,pjjl;
	for(int i=n+1;i<=n+m;i++)
	{
		double zl=123456789,pj=0,zd=0;
		s=i;
		memset(vis,0,sizeof(vis));
		dijkstra();
		for(int i=1;i<=n;i++)
		{
			if(dis[i]==inf)
			continue;
			if(dis[i]<zl)
			zl=dis[i];
			if(dis[i]>zd)
			zd=dis[i];
			pj+=dis[i];
		}
		if(zd>ds)
		continue;
		cout<<pj<<endl;
		pj=pj*1.0/n;
		if(i==n+1)
		{
			mb=n+1;
			zdjl=zl;
			pjjl=pj;
		}
		else
		{
			if(zl>zdjl&&zl<=ds)
			{
				mb=i;
				zdjl=zl;
				pjjl=pj;
			}
			else if(zl==zdjl)
			{
				if(pj<pjjl)
				{
					mb=i;
					pjjl=pj;
				}
			}
			else if(zl<zdjl&&zdjl>ds&&zl<=ds)
			{
				mb=i;
				zdjl=zl;
				pjjl=pj;
			}
		}
	}
	if(!mb)
	cout<<"No Solution";
	else
	{
		cout<<"G"<<mb-n<<endl;
	printf("%.1f ",zdjl);
	int a=(pjjl+0.05)*10;
	double c=a*1.0/10;
	printf("%.1f",c);
	}
	return 0;
}