#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,k;
int main()
{
    
    cin>>l>>r>>k;
    ll ans = 0;
    ll rr;
    for(ll i = 1;i<=r;i = rr+1)
    {
        
        if(i < l)
            rr = min(r/(r/i),(l-1)/((l-1)/i));
        else rr = r/(r/i);
//         cout<<rr<<endl;
        rr = min(r,rr);
        if(r/i - (l-1)/i >=k) 
        {
//             cout<<i<<" "<<rr<<endl;
            ans += rr - i + 1;
        }
    }
    cout<<ans;
    return 0;
}