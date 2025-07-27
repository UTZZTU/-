#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,d,h,y[200010];
double res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&d,&h);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&y[i]);
		}
		res=d*h/2.0*n;
		for(int i=2;i<=n;i++)
		{
			if(y[i-1]+h>y[i])
			{
				double bv=(y[i-1]+h-y[i])*1.0/h;
				res-=(d*h/2.0*bv*bv);
			}
		}
		printf("%.7f\n",res);
	}
	return 0;
}