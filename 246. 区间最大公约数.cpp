#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
ll w[N],n,m,l,r,d;
char op[2];
struct Node
{
	ll l,r;
	ll sum,gcd;
}tr[N*4];
void push_up(Node &u,Node &l,Node &r)
{
	u.sum=l.sum+r.sum;
	u.gcd=__gcd(l.gcd,r.gcd);
}
void push_up(int u)
{
	push_up(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,ll l,ll r)
{
	if(l==r) tr[u]={l,r,w[r]-w[r-1],w[r]-w[r-1]};
	else
	{
		tr[u]={l,r};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
void modify(int u,int x,ll v)
{
	if(tr[u].l==x&&tr[u].r==x)
	{
		ll d=tr[u].sum+v;
		tr[u]={x,x,d,d};
	}
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(x<=mid) modify(u<<1,x,v);
		else modify(u<<1|1,x,v);
		push_up(u);
	}
}
Node query(int u,ll l,ll r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u];
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid) return query(u<<1,l,r);
		else if(l>mid) return query(u<<1|1,l,r);
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
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	build(1,1,n);
	while(m--)
	{
		scanf("%s%lld%lld",op,&l,&r);
		if(*op=='C')
		{
			scanf("%lld",&d);
			modify(1,l,d);
			if(r+1<=n)
			modify(1,r+1,-d);
		}
		else
		{
			auto node1=query(1,1,l);
			Node node2={0,0,0,0};
			if(l+1<=r)
			node2=query(1,l+1,r);
			printf("%lld\n",(ll)abs(__gcd(node1.sum,node2.gcd)));
		}
	}
	return 0;
}