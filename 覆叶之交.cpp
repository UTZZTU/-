#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
typedef long long ll;
const int Maxn=1e5+10;
int yy[Maxn<<1];//离散化后的值
struct Line{
    int x,down_y,up_y,tag;
    bool operator < (const Line l)const{
        return x<l.x;
    }
}line[Maxn<<1];

struct Node{
    int l,r,cover,length;
}tr[Maxn<<2];

void pushUp(int node){
    if(tr[node].cover)tr[node].length=yy[tr[node].r]-yy[tr[node].l];
    else if(tr[node].l+1==tr[node].r)tr[node].length=0;
    else tr[node].length=tr[node<<1].length+tr[node<<1|1].length;
}

void build(int node,int l,int r){
    tr[node]={l,r,0,0};
    if(l+1==r)return;
    int mid=(l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid,r);
    pushUp(node);
}

void update(int node,int l,int r,int tag){
    if(tr[node].l>r || tr[node].r<l)return;
    if(l<=tr[node].l && tr[node].r<=r){
        tr[node].cover+=tag;
        pushUp(node);
        return;
    }
    if(tr[node].l+1==tr[node].r)return;
    int mid=(tr[node].l+tr[node].r)>>1;
    if(l<=mid)update(node<<1,l,r,tag);
    if(mid<r)update(node<<1|1,l,r,tag);
    pushUp(node);
}

signed main(){
//    int n,cnt=0;cin>>n;
    int n=3,cnt=0;
    for(int i=1;i<=n;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int down_y = min(y1,y2),up_y=max(y1,y2);
        line[++cnt]={x1,down_y,up_y,1};
        yy[cnt]=y1;
        line[++cnt]={x2,down_y,up_y,-1};
        yy[cnt]=y2;
    }
    sort(line+1,line+cnt+1);
    sort(yy+1,yy+cnt+1);

    int len = unique(yy+1,yy+cnt+1)-yy-1;
    build(1,1,len);
    int ans=0,y1,y2;
    for(int i=1;i<=2*n;i++){
        ans+=tr[1].length*(line[i].x-line[i-1].x);
        y1= lower_bound(yy+1,yy+len+1,line[i].down_y)-yy;
        y2= lower_bound(yy+1,yy+len+1,line[i].up_y)-yy;
        update(1,y1,y2,line[i].tag);
    }
    cout<<ans<<endl;
    return 0;
}