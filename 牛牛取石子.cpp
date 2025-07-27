#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		ll p=a/3,q=b/3;
		a-=(ll)min(p,q)*3;
		b-=(ll)min(p,q)*3;
		if(a<1||b<1||a<=1&&b<=1)
		{
			printf("niumei\n");
		}
		else
		{
			printf("niuniu\n");
		}
	}
	return 0;
}