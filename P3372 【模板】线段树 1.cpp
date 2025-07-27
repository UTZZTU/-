#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int w[N],n,m,op,x,y,k;
struct Node
{
	int l,r;
	int sum,add;
}tr[N * 4];
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
void build(int u,int l,int r)
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
void modify(int u,int l,int r,int d)
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
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
	push_down(u);
	int mid=tr[u].l+tr[u].r>>1;
	int res=0;
	if(l<=mid) res=query(u<<1,l,r);
	if(r>mid) res+=query(u<<1|1,l,r);
	return res;
}
signed main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	build(1,1,n);
	while(m--)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			modify(1,x,y,k);
		}
		else
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}