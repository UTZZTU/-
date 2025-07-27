#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int n,p,w[N],m,x,t,g,c;
struct Node
{
    int l,r;
    int sum,add,mul;
}tr[N*4];
void push_up(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}
void update(Node &t,int add,int mul)
{
    t.sum=(t.sum*mul%p+add*(t.r-t.l+1)%p)%p;
    t.add=(t.add*mul%p+add)%p;
    t.mul=t.mul*mul%p;
}
void push_down(int u)
{
    update(tr[u<<1],tr[u].add,tr[u].mul);
    update(tr[u<<1|1],tr[u].add,tr[u].mul);
    tr[u].add=0,tr[u].mul=1;
}
void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r,w[r],0,1};
    else
    {
        tr[u]={l,r,0,0,1};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        push_up(u);
    }
}
void modify(int u,int l,int r,int add,int mul)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        update(tr[u],add,mul);
    }
    else
    {
        push_down(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1,l,r,add,mul);
        if(r>mid) modify(u<<1|1,l,r,add,mul);
        push_up(u);
    }
}
int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum%p;
    push_down(u);
    int mid=tr[u].l+tr[u].r>>1;
    int res=0;
    if(l<=mid) res=query(u<<1,l,r);
    if(r>mid) res=(res+query(u<<1|1,l,r))%p;
    return res;
}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=1;i<=n;i++)
    scanf("%lld",&w[i]);
    build(1,1,n);
//    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld%lld%lld",&x,&t,&g);
        if(x==1)
        {
            scanf("%lld",&c);
            modify(1,t,g,0,c);
        }
        else if(x==2)
        {
            scanf("%lld",&c);
            modify(1,t,g,c,1);
        }
        else
        {
            printf("%lld\n",query(1,t,g));
        }
    }
    return 0;
}