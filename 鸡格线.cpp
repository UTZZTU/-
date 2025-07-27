#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
int n,m;
ll tree[N];
bool color[N];
ll sum(int x);
void add(int x,int c);
int lowbit(int x);
int main()
{
    ll ans=0;
    cin>>n>>m;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i],ans+=a[i];
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int l,r,k;
            cin>>l>>r>>k;
            if(sum(r)-sum(l-1)==r-l+1)
                continue;
            for(int i=l;i<=r;i++){
                if(color[i]) continue;
                ans-=a[i];
                int t=k;
                while(t--){
                    a[i]=round(10*sqrt(a[i]));
                    if(a[i]==0||a[i]==99||a[i]==100){
                        break;
                    }
                }
                ans+=a[i];
                if(a[i]==0||a[i]==99||a[i]==100){
                    color[i]=true;
                    add(i,1);
                }
            }
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
ll sum(int x){
    ll res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=c;
}
int lowbit(int x){
    return x&-x;
}
