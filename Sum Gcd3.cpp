#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int n,k,a[1000010],gcds[1000010],res,cnt;
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		gcds[i]=gcd(a[i],k);
		res+=gcds[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt+=(res-gcds[i]);
		cnt+=gcd(a[i]*a[i],k)/gcd(a[i],k);
	}
	printf("%lld",cnt);
	return 0;
}