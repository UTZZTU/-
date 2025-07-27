#include <bits/stdc++.h>
using namespace std;
int ti[100100],n,m,l,cnt[100100],tt[100100],f[100010],ff;
struct edge
{
	int u,v;
}e[100010];
bool cmp(edge x,edge y)
{
	if(x.v!=y.v)
	return x.v<y.v;
	else
	return x.u<y.u;
}
struct node
{
	int t,pos,pp;
	inline bool operator<(const node &x) const
	{
		if(t!=x.t)
		{
			return t>=x.t;
		}
		else if(t==x.t&&pp!=x.pp)
		{
			return pp>x.pp;
		}
		else
		{
			return pos>x.pos;
		}
	}
};
priority_queue<node> q;
int main ()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tt[i]);
	}
	for(int i=1;i<=l;i++)
	{
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=min(l,m);i++)
	{
		q.push({ti[i]+tt[f[i]],i,i});
		cnt[i]++;
		ti[i]+=tt[f[i]];
	}
	for(int i=m+1;i<=l;i++)
	{
		node x=q.top();
		q.pop();
		e[++ff].u=x.pos;
		e[ff].v=x.t;
		q.push({ti[x.pp]+tt[f[i]],i,x.pp});
		cnt[x.pp]++;
		ti[x.pp]+=tt[f[i]];
	}
	while(q.size())
	{
		node x=q.top();
		q.pop();
		e[++ff].u=x.pos;
		e[ff].v=x.t;
	}
	sort(e+1,e+1+ff,cmp);
	for(int i=1;i<=ff;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%d:%d",e[i].u,e[i].v);
	}
	printf("\n");
	for(int i=1;i<=m;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%d",cnt[i]);
	}
	return 0;
}