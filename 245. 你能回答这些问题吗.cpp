#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
typedef long long ll;
ll w[N],n,m,k,x,y;
struct Node
{
	ll l,r;
	ll sum,lmax,rmax,tmax;
}tr[N*4];
void push_up(Node &u,Node &l,Node &r)
{
	u.sum=l.sum+r.sum;
	u.lmax=max(l.lmax,l.sum+r.lmax);
	u.rmax=max(r.rmax,r.sum+l.rmax);
	u.tmax=max(max(l.tmax,r.tmax),l.rmax+r.lmax);
}
void push_up(int u)
{
	push_up(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r)
{
	if(l==r) tr[u]={l,r,w[r],w[r],w[r],w[r]};
	else
	{
		tr[u]={l,r};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
Node query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u];
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid)
		{
			return query(u<<1,l,r);
		}
		else if(l>mid)
		{
			return query(u<<1|1,l,r);
		}
		else
		{
			auto left=query(u<<1,l,r);
			auto right=query(u<<1|1,l,r);
			Node res;
			push_up(res,left,right);
			return res;
		}
	}
}
void modify(int u,int x,ll v)
{
	if(tr[u].l==x&&tr[u].r==x) tr[u]={x,x,v,v,v,v};
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(x<=mid) modify(u<<1,x,v);
		else modify(u<<1|1,x,v);
		push_up(u);
	}
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	build(1,1,n);
	while(m--)
	{
		scanf("%lld%lld%lld",&k,&x,&y);
		if(k==2)
		{
			modify(1,x,y);
		}
		else
		{
			if(x>y) swap(x,y);
			printf("%lld\n",query(1,x,y).tmax);
		}
	}
	return 0;
}