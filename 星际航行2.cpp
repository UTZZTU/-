#include <bits/stdc++.h>
using namespace std;
int n,p,v,maxx,cnt,pv,fa[100010],speed[100010];
map<int,int> mp;
struct node
{
	int u,v;
	double w;
	inline bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
struct edge{
	int p,v,idx;
}e[100010];
bool cmp(edge a,edge b)
{
	return a.p<b.p;
}
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x; 
}
priority_queue<node> q;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d%d",&p,&v);
		speed[i]=v;
		e[i].p=p;
		e[i].v=v;
		e[i].idx=i;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		if(e[i-1].p==e[i].p)
		{
			q.push({e[i-1].idx,e[i].idx,0});
		}
		else if(e[i-1].v>e[i].v)
		{
			q.push({e[i-1].idx,e[i].idx,(e[i].p-e[i-1].p)*1.0/(e[i-1].v-e[i].v)});
		}
	}
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		int u=x.u,v=x.v;
		int eu=find(u),ev=find(v);
		if(eu!=ev)
		{
			if(speed[eu]>speed[ev])
			{
				fa[eu]=ev;
				speed[ev]=min(speed[ev],speed[eu]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int u=find(i);
		mp[u]++;
		maxx=max(maxx,mp[u]);
	}
	printf("%d",maxx);
	return 0;
}