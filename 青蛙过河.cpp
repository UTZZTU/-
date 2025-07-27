#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100010],n,s;
bool check(ll x)
{
	for(ll i=1;i<n;i++)
	{
		ll j=i+x-1;
		if(j<n)
		{
			if(f[j]-f[i-1]<2*s) return false;
		}
	}
	return true;
}
int main ()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
	cin>>f[i],f[i]+=f[i-1];
	ll l=1,r=1e18;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
//		cout<<l<<" "<<r<<endl;
	}
	cout<<l;
	return 0;
}