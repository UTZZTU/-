#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define fr(i,x,y) for(int i=x;i<y;i++)
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
ll N;
vector<ll> A(N), ST(N);
void build(ll node, ll L, ll R)
{
ll mid = (L + R) / 2;
 build(2 * node+1, L, mid);
 build(2 * node+2, mid + 1, R);
 ST[node] = ST[2 * node+1] + ST[2 * node+2];
 }
//----------------------------//
void update(ll node, ll L, ll R, ll idx, ll val)
{
if (L == R) {
 A[idx] += val;
 ST[node] += val;
 }else {
 ll mid = (L + R) / 2;
 if (L <= idx and idx <= mid)
update(2 * node+1, L, mid, idx, val);
  else
update(2 * node+2, mid + 1, R, idx, val);
 ST[node] = ST[2 * node+1] + ST[2 * node+2];
   }}
//----------------------------//
ll query(ll node, ll tl, ll tr, ll l, ll r)
{
   if (r < tl or tr < l)
 return 0;
 if (l <= tl and tr <= r)
 return ST[node];
ll tm = (tl + tr) / 2;
  return query(2 * node+1, tl, tm, l, r)
+ query(2 * node + 2, tm + 1, tr, l, r);
}
struct range{
 ll l,r,ind;
bool operator < (const range &other) const{
if(l==other.l){
return r>other.r;}
 return l<other.l;
}};
ll binexp(ll a,ll b,ll m){
ll result =1;
while(b>0){
if(b&1){
result=(result*a)%m;
}
a=(a*a)%m;
b>>=1;
}
return result;
}


void solve()
{

    ll n,m,k,d;
    cin>>n>>m>>k>>d;

    vector<vector<ll>> v(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
      for(ll j=0;j<m;j++){
        cin>>v[i][j];
      }
    }

    vector<ll> temp;


    

    for(ll i=0;i<n;i++){
         vector<ll> dp(m,1e14);
         dp[m-1]=1;
         multiset<ll> ms;
         ms.insert(1);
         for(ll j=m-2;j>=0;j--){
           if((j+d+2)<m){
             ms.erase(ms.find(dp[j+d+2]));
           }
           dp[j]=min(dp[j],*ms.begin()+v[i][j]+1);
          
            ms.insert(dp[j]);
         }
      
       temp.push_back(dp[0]);
    
    }


    for(ll i=1;i<n;i++){
      temp[i]+=temp[i-1];
    }



    ll ans=temp[k-1];

    for(ll i=0;i+k<n;i++){
      ans=min(ans,temp[i+k]-temp[i]);
    }

    cout<<ans<<endl;


    

   






}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;while(t--)
{solve();}
return 0;
}