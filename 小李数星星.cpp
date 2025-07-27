#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	ll n,i,a,b,max1=0,max2=0,min1=1000000,min2=1000000,t;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		if(a>max1)
		max1=a;
		if(a<min1)
		min1=a;
		if(b>max2)
		max2=b;
		if(b<min2)
		min2=b;
	}
	t=max(max1-min1,max2-min2);
	printf("%lld",t*t);
	return 0;
}