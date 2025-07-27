#include <stdio.h>
#include <math.h>
typedef long long ll;
int main ()
{
	ll x,i;
	ll s,w;
	scanf("%lld",&x);
	s=1;
	for(i=0;;i++)
	{
		if(s%x==0)
		{
			w=s/x;
			printf("%lld %lld",w,i+1);
			break;
		}
		s=s*10+1;
	}
	return 0;
}