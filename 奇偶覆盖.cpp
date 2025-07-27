#include<bits/stdc++.h>
using namespace std;
#define lson (x<<1)
#define rson (x<<1|1)
typedef long long ll;
const int N=7e5+100;
int n,cnt;
ll xx1,xx2,yy1,yy2,X[N<<1];
struct scanline{
    ll l,r,h;
    int mark;
    bool operator < (const scanline &rhs) const {
        return h<rhs.h;
    }
}line[N<<1];
struct segtree{
    int l,r,sum;
    ll len1,len2;//1 ji 2 ou
}tree[N<<1];
void build(int x,int l,int r){
    tree[x].l=l,tree[x].r=r;
    tree[x].len1=0;
    tree[x].len2=0;
    tree[x].sum=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    return ;
}
void pushup(int x,int l,int r){
    if(tree[x].sum){
        if(tree[x].sum&1){
            tree[x].len2=tree[lson].len1+tree[rson].len1;//注意坑点 奇+奇=偶
            tree[x].len1=(X[r+1]-X[l])-tree[x].len2;
        }else{
            tree[x].len1=tree[lson].len1+tree[rson].len1;
            tree[x].len2=(X[r+1]-X[l])-tree[x].len1;
        }
    }else{
        tree[x].len1=tree[lson].len1+tree[rson].len1;
        tree[x].len2=tree[lson].len2+tree[rson].len2;//与上面不同，仅统计个数
    }
}
void update(int L,int R,int c,int l,int r,int x){
    if(L<=l&&R>=r){
        tree[x].sum+=c;
        pushup(x,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,c,l,mid,lson);
    if(R>mid) update(L,R,c,mid+1,r,rson);
    pushup(x,l,r);
}
int get(int x,int tot){
    return lower_bound(X+1,X+tot+1,x)-X;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>xx1>>yy1>>xx2>>yy2;
        X[2*i-1]=xx1,X[2*i]=xx2;
        line[2*i-1]=(scanline){xx1,xx2,yy1,1};
        line[2*i]=(scanline){xx1,xx2,yy2,-1};
    }
    n<<=1;
    sort(line+1,line+n+1);
    sort(X+1,X+n+1);
    int tot=unique(X+1,X+n+1)-X-1;
    build(1,1,tot-1);
    ll ans1=0,ans2=0;
    for(int i=1;i<n;i++){
        update(get(line[i].l,tot),get(line[i].r,tot)-1,line[i].mark,1,tot,1);
        ans1+=tree[1].len1*(line[i+1].h-line[i].h);
        ans2+=tree[1].len2*(line[i+1].h-line[i].h);
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}
