#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef long long ll;
ll n,m,w[N],d,l,r,t;
struct Node
{
    ll l,r;
    ll maxx,pos,add;
}tr[N*4];
void push_up(int u)
{
	tr[u].maxx=-0x3f3f3f3f;
	tr[u].pos=-1;
    if(tr[u<<1].maxx>tr[u].maxx)
    {
    	tr[u].maxx=tr[u<<1].maxx;
    	tr[u].pos=tr[u<<1].pos;
	}
	else if(tr[u<<1].maxx==tr[u].maxx)
	{
		if(tr[u<<1].pos<tr[u].pos)
		{
			tr[u].pos=tr[u<<1].pos;
		}
	}
	if(tr[u<<1|1].maxx>tr[u].maxx)
    {
    	tr[u].maxx=tr[u<<1|1].maxx;
    	tr[u].pos=tr[u<<1|1].pos;
	}
	else if(tr[u<<1|1].maxx==tr[u].maxx)
	{
		if(tr[u<<1|1].pos<tr[u].pos)
		{
			tr[u].pos=tr[u<<1|1].pos;
		}
	}
}
void push_down(int u)
{
    if(tr[u].add)
    {
        tr[u<<1].add+=tr[u].add,tr[u<<1].maxx+=tr[u].add;
        tr[u<<1|1].add+=tr[u].add,tr[u<<1|1].maxx+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,ll l,ll r)
{
    if(l==r) tr[u]={l,r,w[r]+r,r,0};
    else
    {
        tr[u]={l,r};
        tr[u].add=0;
        tr[u].pos=-1;
        tr[u].maxx=-1;
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
        tr[u].maxx+=d;
//        cout<<tr[u].l<<" "<<tr[u].r<<endl;
//        cout<<tr[u].maxx<<endl;
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
pair<ll,ll> query(int u,ll l,ll r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return {tr[u].maxx,tr[u].pos};
    push_down(u);
    int mid=tr[u].l+tr[u].r>>1;
    pair<ll,ll> p={0,0};
    if(l<=mid) p=query(u<<1,l,r);
    if(r>mid) 
    {
    	auto q=query(u<<1|1,l,r);
    	if(q.first>p.first)
    	{
    		p=q;
		}
		else if(q.first==p.first)
		{
			p.second=min(p.second,q.second);
		}
	}
    return p;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			auto p=query(1,1,n);
			printf("%lld ",p.first);
			modify(1,p.second,p.second,(ll)-1e9);
			if(p.second!=n)
			modify(1,p.second+1,n,-1);
		}
		printf("\n");
	}
//    scanf("%lld%lld",&n,&m);
//    for(int i=1;i<=n;i++)
//    {
//        scanf("%lld",&w[i]);
//    }
//    build(1,1,n);
//    while(m--)
//    {
//        scanf("%s%lld%lld",op,&l,&r);
//        if(*op=='C')
//        {
//            scanf("%lld",&d);
//            modify(1,l,r,d);
//        }
//        else
//        {
//            printf("%lld\n",query(1,l,r));
//        }
//    }
    return 0;
}