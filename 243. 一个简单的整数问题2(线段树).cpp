#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
ll n,m,w[N],d,l,r;
char op[2];
struct Node
{
	ll l,r;
	ll sum,add;
}tr[N*4];
void push_up(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void push_down(int u)
{
	if(tr[u].add)
	{
		tr[u<<1].add+=tr[u].add,tr[u<<1].sum+=(tr[u<<1].r-tr[u<<1].l+1)*tr[u].add;
		tr[u<<1|1].add+=tr[u].add,tr[u<<1|1].sum+=(tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add;
		tr[u].add=0;
	}
}
void build(int u,ll l,ll r)
{
	if(l==r) tr[u]={l,r,w[r],0};
	else
	{
		tr[u]={l,r};
		tr[u].add=0;
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
void modify(int u,ll l,ll r,ll d)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].add+=d;
		tr[u].sum+=(tr[u].r-tr[u].l+1)*d;
	}
	else
	{
		push_down(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,d);
		if(r>mid) modify(u<<1|1,l,r,d);
		push_up(u);
	}
}
ll query(int u,ll l,ll r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
	push_down(u);
	int mid=tr[u].l+tr[u].r>>1;
	ll res=0;
	if(l<=mid) res=query(u<<1,l,r);
	if(r>mid) res+=query(u<<1|1,l,r);
	return res;
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
			modify(1,l,r,d);
		}
		else
		{
			printf("%lld\n",query(1,l,r));
		}
	}
	return 0;
}