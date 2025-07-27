#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,le,ri,k;
bool check(ll x)
{
	ll z,y=r/x*x;
	z=y-(k-1)*x;
	if(y>=x&&z>=x&&z>=l)
	return true;
	else
	return false;
}
int main ()
{
	scanf("%lld %lld %lld",&l,&r,&k);
	le=1;
	ri=(r-l)/(k-1);
	while(le<ri)
	{
		ll mid=(le+ri+1)/2;
		if(check(mid))
		le=mid;
		else
		ri=mid-1;
	}
	cout<<le;
	return 0;
}