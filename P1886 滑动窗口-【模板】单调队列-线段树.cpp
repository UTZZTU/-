#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int w[N],n,k;
struct Node
{
	int l,r;
	int mn,mx;
}tr[N * 4];
void push_up(int u)
{
	tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
	tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,w[r],w[r]};
	}else
	{
		tr[u]={l,r};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
int query1(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mn;
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		int minn=0x3f3f3f3f3f3f3f3f;
		if(l<=mid) minn=min(minn,query1(u<<1,l,r));
		if(r>mid) minn=min(minn,query1(u<<1|1,l,r));
		return minn;
	}
}
int query2(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mx;
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		int maxx=-0x3f3f3f3f3f3f3f3f;
		if(l<=mid) maxx=max(maxx,query2(u<<1,l,r));
		if(r>mid) maxx=max(maxx,query2(u<<1|1,l,r));
		return maxx;
	}
}
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&w[i]);
	build(1,1,n);
	for(int i=k;i<=n;i++)
	{
		printf("%lld ",query1(1,i-k+1,i));
	}
	printf("\n");
	for(int i=k;i<=n;i++)
	{
		printf("%lld ",query2(1,i-k+1,i));
	}
	return 0;
}