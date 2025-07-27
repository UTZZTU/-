#include <stdio.h>
#include <math.h>
int main ()
{
	long long k,i,n,x;
	scanf("%lld",&n);
	for(i=sqrt(4+2*n)-1;;i++)
	{
		if((i*(i+1)-2*n)%4==0)
		{
			x=(i*(i+1)-2*n)/4;
			if(x<=0)
			continue;
			else
			{
				printf("%lld %lld",x,i);
				break;
			}
		}
	}
	return 0;
}
