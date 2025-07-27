#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],res,ans;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		res+=a[i]*(ans-a[i]);
	}
	printf("%lld",res);
	return 0;
}