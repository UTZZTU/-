#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll x=floor(sqrt(2*n));
		while(x*(x-1)/2<n) x++;
		if(x*(x-1)/2==n)
		{
			cout<<x<<endl;
		}
		else
		{
			cout<<x-1+(n-(x-1)*(x-2)/2)<<endl;
		}
	}
	return 0;
}