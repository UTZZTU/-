#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,y,a,b,c;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&y);
		a=n/x,b=n/y,c=n;
		c/=x*y/__gcd(x,y);
		a-=c,b-=c;
		a=n-a;
		printf("%lld\n",n*(n+1)/2-(a*(a+1)/2)-(b*(b+1)/2));
	}
	return 0;
}