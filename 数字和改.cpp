#include<iostream>
using namespace std;
typedef long long ll;
ll n,s;
ll sum(ll n){
    ll summ=0;
    while(n>0){
        summ+=n%10;
        n/=10;
    }
    return summ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        ll a=10,b=n;
        while(sum(n)>s){
            n+=a-n%a;
            a*=10;
        }
        cout<<n-b<<endl;
    }
    return 0;
}
