#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
typedef long long ll;
ll w1[N],n,m,k,x,y,w2[N];
struct Node
{
    ll l,r;
    ll sum1,lmax1,rmax1,tmax1,sum2,lmax2,rmax2,tmax2;
}tr[N*4];
void push_up(Node &u,Node &l,Node &r)
{
    u.sum1=l.sum1+r.sum1;
    u.lmax1=max(l.lmax1,l.sum1+r.lmax1);
    u.rmax1=max(r.rmax1,r.sum1+l.rmax1);
    u.tmax1=max(max(l.tmax1,r.tmax1),l.rmax1+r.lmax1);
    
    u.sum2=l.sum2+r.sum2;
    u.lmax2=max(l.lmax2,l.sum2+r.lmax2);
    u.rmax2=max(r.rmax2,r.sum2+l.rmax2);
    u.tmax2=max(max(l.tmax2,r.tmax2),l.rmax2+r.lmax2);
}
void push_up(int u)
{
    push_up(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r,w1[r],w1[r],w1[r],w1[r],w2[r],w2[r],w2[r],w2[r]};
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
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&w1[i]);
        w2[i]=-w1[i];
    }
    build(1,1,n);
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
//        if(k==2)
//        {
//            modify(1,x,y);
//        }
//        else
//        {
//            if(x>y) swap(x,y);
			Node p=query(1,x,y);
            printf("%lld\n",max(p.tmax1,p.tmax2));
//        }
    }
    return 0;
}