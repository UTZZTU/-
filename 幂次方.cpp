#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 233333;
ll fastpower(ll a,ll b,ll p)
{
	ll result=1;
	while(b)
	{
		if(b&1)
		result=result*a%p;
		a=a*a%p;
		b/=2;
	}
	return result;
}
int main ()
{
	ll x,n;
	cin>>x>>n;
	cout<<fastpower(x,n,INF);
	return 0;
}