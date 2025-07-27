#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
ll num[maxn],res[maxn];
ll dis[maxn],vis[maxn];
ll q[maxn],hh,tt=-1;
ll n;
ll gcd(int a,int b){
return b==0?a:gcd(b,a%b);
}
ll lcm(int a,int b){
return a/gcd(a,b)*b;
}
ll bfs(int u){
for(int i=1;i<=n;i++){
q[i]=0;vis[i]=0;dis[i]=0;
}
q[++tt]=u;
vis[u]=1;
while(hh<=tt){
int x=q[hh++];
if(vis[x]==2) return dis[x];
if(vis[num[x]]&&num[x]!=u) continue;
q[++tt]=num[x];
vis[num[x]]++;
dis[num[x]]=dis[x]+1;
}
}
int main(){
cin>>n;
for(ll i=1;i<=n;i++) cin>>num[i];
for(ll i=1;i<=n;i++)
res[i]=bfs(i);
//for(int i=1;i<=n;i++)
//cout<<"#"<<i<<" "<<res[i]<<endl;
ll sum=1;
for(ll i=1;i<=n;i++) 
sum=lcm(sum,res[i]);
cout<<sum<<endl;
return 0;
}

