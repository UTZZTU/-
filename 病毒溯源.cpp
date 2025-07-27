#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll N = 1e4 + 10;
ll p[N];
ll a,k;
ll n;
ll maxn = -1;
vector<ll>ans[N];
ll find_root(ll x,ll val)
{
    while(p[x] != x){
        x = p[x];
        val++;
    }
    return val;
}
stack<ll>box;
int main()
{
    scanf("%d",&n);
    for(ll i = 0;i < n;i++){
        p[i] = i;
    }
    for(ll i = 0;i < n;i++){
        scanf("%d",&k);
        for(ll j = 0;j < k;j++){
            scanf("%d",&a);
            p[a] = i;
        }
    }
    for(ll i = 0;i < n;i++){
        ll tmp = find_root(i,1);
        if(tmp > maxn){
            maxn = tmp;
        }
    }
    ll idx = 0;
    for(ll i = 0;i < n;i++){
        if(find_root(i,1) == maxn){
            ll tmp = i;
            while(p[tmp] != tmp){
                box.push(tmp);
                tmp = p[tmp];
            }
            box.push(tmp);
            while(box.size()){
                ans[idx].push_back(box.top());
                box.pop();
            }
            idx++;
        }
    }
    sort(ans, ans + idx - 1);
    printf("%d\n",maxn);
    for(ll i = 0;i < ans[0].size();i++){
        if(i)printf(" ");
        printf("%d",ans[0][i]);
    }
    return 0;
}