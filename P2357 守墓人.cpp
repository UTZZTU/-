#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,f,w[N],op,a,b,k;
struct Node
{
	int l,r;
	int sum,cnt;
}tr[N * 4];
void update(int u,int cnt)
{
	tr[u].sum+=(tr[u].r-tr[u].l+1)*cnt;
	tr[u].cnt+=cnt;
}
void push_up(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void push_down(int u)
{
	update(u<<1,tr[u].cnt);
	update(u<<1|1,tr[u].cnt);
	tr[u].cnt=0;
	push_up(u);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,w[r],0};
	}
	else
	{
		tr[u]={l,r};
		tr[u].cnt=0;
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
void modify(int u,int l,int r,int x)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].sum+=(tr[u].r-tr[u].l+1)*x;
		tr[u].cnt+=x;
	}
	else
	{
		push_down(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,x);
		if(r>mid) modify(u<<1|1,l,r,x);
		push_up(u);
	}
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		return tr[u].sum;
	}
	else
	{
		push_down(u);
		int mid=tr[u].l+tr[u].r>>1;
		int res=0;
		if(l<=mid) res=query(u<<1,l,r);
		if(r>mid) res+=query(u<<1|1,l,r);
		return res; 
	}
}
signed main ()
{
	scanf("%lld%lld",&n,&f);
	for(int i=1;i<=n;i++)
	scanf("%lld",&w[i]);
	build(1,1,n);
	while(f--)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld%lld",&a,&b,&k);
			modify(1,a,b,k);
			
		}else if(op==2)
		{
			scanf("%lld",&k);
			modify(1,1,1,k);
		}else if(op==3)
		{
			scanf("%lld",&k);
			modify(1,1,1,-k);
		}else if(op==4)
		{
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",query(1,a,b));
		}else
		{
			printf("%lld\n",query(1,1,1));
		}
	}
	return 0;
}