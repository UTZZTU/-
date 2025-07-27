#include <bits/stdc++.h>
using namespace std;
#define INF 1234567890
typedef long long ll;
int dis[1010],vis[1010],head[1010],cnt,n,m,b,k,pp[1010],s;
struct Edge
{
	int u,v,w1,w2,next;
}e[1010];
void add(int u,int v,int w1,int w2)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w1=w1;
	e[cnt].w2=w2;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct node
{
	int w,now;
	inline bool operator<(const node &x) const
	{
		return w>x.w;
	}
};

void dijstra()
{
	priority_queue<node> q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
//		vis[i]=0;
		pp[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
//		cout<<"yyyyy"<<endl;
		node x=q.top();
		q.pop();
		int u=x.now;
//		if(vis[u]) continue;
//		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			int w1=e[i].w1;
			int w2=e[i].w2;
//			cout<<"v:"<<v<<endl;
//			cout<<dis[v]<<endl;
			if(dis[v]>dis[u]+w1)
			{
				dis[v]=dis[u]+w1;
				pp[v]=pp[u]+w2;
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+w1)
			{
				if(pp[v]<pp[u]+w2)
				{
					pp[v]=pp[u]+w2;
					q.push({dis[v],v});
				}
			}
		}
	}
}
int main ()
{
	cin>>b>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w1,w2;
		cin>>u>>v>>w1>>w2;
		add(u,v,w1,w2);
		add(v,u,w1,w2);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s;
		dijstra();
		vector<int> vec;
		for(int j=1;j<=n;j++)
		{
			if(j==s) continue;
			if(dis[j]<=b)
			{
				vec.push_back(j);
			}
//			cout<<dis[j]<<" ";
		}
		if(vec.empty())
		{
			cout<<"T_T"<<endl;
		}
		else
		{
			for(int i=0;i<vec.size();i++)
			{
				if(i!=0) cout<<" ";
				cout<<vec[i];
			}
			cout<<endl;
			vector<int> v;
			int maxx=0;
			for(int i=0;i<vec.size();i++)
			{
				if(pp[vec[i]]>maxx)
				{
					maxx=pp[vec[i]];
					v.clear();
					v.push_back(vec[i]);
				}
				else if(pp[vec[i]]==maxx)
				{
					v.push_back(vec[i]);
				}
			}
			for(int i=0;i<v.size();i++)
			{
				if(i!=0) cout<<" ";
				cout<<v[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
