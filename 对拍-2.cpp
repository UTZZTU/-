#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,s;
bool check(ll n)
{
	for(ll i=0;i<=n;i++)
	{
		ll j=n-i;
		if((i&j)==a) 
		{
			cout<<i<<" "<<j<<" "<<(i&j)<<endl;
			return true;
		}
	}
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>s;
		if(check(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}