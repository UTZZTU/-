#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main ()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			printf("%lld ^ %lld = %lld ",i,j,(ll)pow(i,j));
		}
		printf("\n");
	}
	return 0;
}