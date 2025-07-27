#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
int n,m,s,d,head[3010],dis[1010],cnt,pre[1010],v[1010],num[1010],vis[1010],pp[1010];
struct edge
{
	int u,v,w,next;
}e[3010];
struct node
{
	int w,x;
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<node> q;
void dijkstra()
{
	dis[s]=0;
	num[s]=v[s];
	pp[s]=1;
	q.push({0,s});
	while(!q.empty())
	{
		auto p=q.top();
		q.pop();
		int u=p.x;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int j=e[i].v,k=e[i].w;
			if(dis[j]>dis[u]+k)
			{
				dis[j]=dis[u]+k;
				num[j]=num[u]+v[j];
				pre[j]=u;
				pp[j]=pp[u];
				q.push({dis[j],j});
			}
			else if(dis[j]==dis[u]+k)
			{
				pp[j]+=pp[u];
				if(num[j]<num[u]+v[j])
				{
					num[j]=num[u]+v[j];
					pre[j]=u;
				}
			}
		}
	}
}
int main ()
{
	cin>>n>>m>>s>>d;
	s++,d++;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		pre[i]=i;
		dis[i]=inf;
	}
	while(m--)
	{
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		uu++,vv++;
		add(uu,vv,ww);
		add(vv,uu,ww);
	}
	dijkstra();
	vector<int> vec;
	int y=d;
	while(y!=pre[y])
	{
		vec.push_back(y);
		y=pre[y];
	}
	vec.push_back(y);
	reverse(vec.begin(),vec.end());
	cout<<pp[d]<<" "<<num[d]<<endl;
	for(int i=0;i<vec.size();i++)
	{
		if(i!=0) cout<<" ";
		cout<<vec[i]-1;
	}
	return 0;
}
