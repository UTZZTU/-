#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
ll n,k;
bool check(ll k)
{
    int ans=0;
    ll u=floor(sqrt(k));
    if(u*u!=k)
    return false;
    if(k==1)
    return false;
    else{
        for(int i=1;i<u;i++)
        {
            if(k%i==0)
            ans++;
            if(ans>1)
            return false;
        }
    }
    return ans==1;
}
int main( )
{
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&k);
        if(check(k))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}