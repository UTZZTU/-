#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a[100010],k,x,b[100010];
int main ()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	b[i]=b[i-1]+a[i];
	while(q--)
	{
		scanf("%lld%lld",&k,&x);
		ll pos=upper_bound(a+1,a+1+n,x)-a;
		pos--;
		printf("%lld\n",b[pos]-b[max((ll)0,pos-k)]);
	}
	return 0;
}