#include <iostream>
using namespace std;
typedef long long ll;
ll f[1000010],limit,n;
int main ()
{
	ll i=2;
	f[0]=f[1]=1;
	for(i;;i++)
	{
		f[i]=f[i-1]*i;
		if(f[i]>6227020800)
		{
			limit=i;
			break;
		}
	}
	while(~scanf("%lld",&n))
	{
		if(n>=limit)
		printf("Overflow!\n");
		else if(n<0)
		{
			if(n&1)
			printf("Overflow!\n");
			else
			printf("Underflow!\n");
		}
		else if(f[n]<10000)
		printf("Underflow!\n");
		else
		printf("%lld\n",f[n]);
	}
	return 0;
}