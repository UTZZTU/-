#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define int __int128
#define double long double
typedef pair<int,int>PII;
typedef pair<string,int>PSI;
typedef pair<string,string>PSS;
const int N=1e5+5,INF=0x3f3f3f3f,Mod=1e9+7,mod=998244353;
const double eps=1e-6;
int cnt,primes[N],phi[N];
bool st[N];
int n;
void get_phi(int n){
    phi[1]=1;
    for(int i=2;i<=n;++i){
        if(!st[i])phi[i]=i-1,primes[cnt++]=i;
        for(int j=0;primes[j]*i<=n;++j){
            int t=i*primes[j];
            st[t]=true;
            if(i%primes[j]==0){
                phi[t]=phi[i]*primes[j];
                break;
            }
            else phi[t]=phi[i]*(primes[j]-1);
        }
    }
}

void solve(){
    cin>>n;
    vector<int>a(n+1),num(N);
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a.begin()+1,a.end());
    int ans=0;
    for(int i=1;i<n;++i){
        int s=0,x=a[i];
        for(int j=1;j*j<=x;++j){
            if(x%j)continue;
            s+=phi[j]*num[j]++;
//            cout<<num[j]<<" "<<j<<endl;
            if(j*j!=x)s+=phi[x/j]*num[x/j]++;
        }
        ans+=s*(n-i);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    get_phi(100000);
    while(t--){
        solve();
    }
    return 0;
}