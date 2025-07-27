#include <iostream>
using namespace std;
const int mxn = 1e5+7 ;
#define ll long long
ll n,m,t,k,ans,cnt;
void solve() 
{
    for(cin>>t;t;t--){
        cin>>n;
        ans = 0 ; k = 0 ; cnt = -1 ;
        for(int i=1;i<=n;i++){
            cin>>k;
            ans += k ;
            cnt = max(cnt,k);
        }    
        if(n*cnt<cnt+ans)
            cout<<abs(ans-n*cnt)<<endl;
        else 
            cout<<-1<<endl;
    }    
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}