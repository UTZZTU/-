#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int w[N],n,m,op,x,y;
string s;
struct Node
{
	int l,r;
	int sum,cnt;
}tr[N * 4];
void update(int u,int cnt)
{
	tr[u].cnt+=cnt;
	if(cnt%2)
	{
		tr[u].sum=(tr[u].r-tr[u].l+1)-tr[u].sum;
	}
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
		tr[u].cnt+=x;
		if(x%2)
		{
			tr[u].sum=(tr[u].r-tr[u].l+1)-tr[u].sum;
		}
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
		int res=0;
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) res=query(u<<1,l,r);
		if(r>mid) res+=query(u<<1|1,l,r);
		return res;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		w[i+1]=s[i]-'0';
	}
	build(1,1,n);
	while(m--)
	{
		cin>>op>>x>>y;
		if(op) cout<<query(1,x,y)<<endl;
		else modify(1,x,y,1);
	}
	return 0;
}