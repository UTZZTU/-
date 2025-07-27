#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main ()
{
	cin>>n>>s;
	if(s%n==0)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",s/n);
		}
	}
	else
	{
		ll pos=s%n;
		for(int i=1;i<=n;i++)
		{
			if(i<=n-pos) printf("%lld ",s/n);
			else printf("%lld ",s/n+1);
		}
	}
	return 0;
}