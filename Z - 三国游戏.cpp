#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll M=5e7;
const int mod=1e9+7;
ll a[510][510];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }
    ll maxx=0;
    for(ll i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+n+1);
        maxx=max(maxx,a[i][n-1]);
    }
    cout<<1<<endl;
    cout<<maxx<<endl;
    return 0;
}