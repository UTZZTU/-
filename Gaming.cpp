#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[1000010],r[1000010],ans,n,m,li,ri,si;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>li>>ri>>si;
        l[ri]+=si;
        r[li]+=si;
    }
    for(int i=1;i<=m;i++)
        l[i]+=l[i-1];
    for(int i=m;i>=1;i--)
        r[i]+=r[i+1];
    for(int i=1;i<=m;i++)
        ans=max(ans,l[i-1]+r[i+1]);
    cout<<ans;
    return 0;
}