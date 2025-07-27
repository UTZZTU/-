#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
	ll n;
	cin>>n;
	ll i=1;
	while(i*2ll<=n)
	{
		i*=2ll;
	}
	cout<<i;
	return 0;
}
