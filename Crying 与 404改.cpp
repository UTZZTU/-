#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct dates{
    int l,r,sum;
}date[N*32];
int root[N],idx;
void build(int &rt,int l,int r)
{
    if(!rt) rt=++idx;
    if(l==r) return;
    int mid=l+r>>1;
    build(date[rt].l,l,mid);
    build(date[rt].r,mid+1,r);
}
void motify(int pre,int &cur,int l,int r,int x)
{
    if(!cur) cur=++idx;
    date[cur].sum=date[pre].sum+1;
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid)
    {
        date[cur].r=date[pre].r;
        motify(date[pre].l,date[cur].l,l,mid,x);
    }
    else{
        date[cur].l=date[pre].l;
        motify(date[pre].r,date[cur].r,mid+1,r,x);
    }
}
int query(int pre,int cur,int l,int r,int k)
{
    if(l==r) return l;
    int mid=l+r>>1;
    int len=mid-l+1;
    int zsum=date[date[cur].l].sum-date[date[pre].l].sum;
    if(k<=len-zsum) return query(date[pre].l,date[cur].l,l,mid,k);
    else return query(date[pre].r,date[cur].r,mid+1,r,k-(len-zsum));
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n+1);
    build(root[0],0,n-1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        motify(root[i-1],root[i],0,n-1,v[i]);
    }
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        if(k>n-(r-l+1)) cout<<k+r-l<<'\n';
        else cout<<query(root[l-1],root[r],0,n-1,k)<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T=1;
    while(T--){solve();}
    return 0;
}