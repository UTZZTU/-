#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main ()
{
	cin>>n;
	ll x=ceil(sqrt(2*n*1.0));
	if(x*(x-1)/2>=n)
	x-=1;
	ll t=x*x;
	for(ll i=x*(x+1)/2;i>n;i--)
	{
		t-=2;
	}
    cout<<t;
	return 0;
}