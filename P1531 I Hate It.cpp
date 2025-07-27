#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e5+10;
int w[N],n,m,a,b;
char op[2];
struct Node
{
	int l,r;
	int val,mx;
}tr[N * 4];
void push_up(int u)
{
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
void modify(int u,int l,int r,int c)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		if(tr[u].val<c)
		{
			tr[u].val=c;
			tr[u].mx=c;
		}
	}
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,c);
		if(r>mid) modify(u<<1|1,l,r,c);
		push_up(u);
	}
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mx;
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		int maxx=0;
		if(l<=mid) maxx=max(maxx,query(u<<1,l,r));
		if(r>mid) maxx=max(maxx,query(u<<1|1,l,r));
		return maxx;
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i]);
	build(1,1,n);
	while(m--)
	{
		scanf("%s %d %d",op,&a,&b);
		if(op[0]=='Q')
		{
			printf("%d\n",query(1,a,b));
		}
		else
		{
			modify(1,a,a,b);
		}
	}
	return 0;
}