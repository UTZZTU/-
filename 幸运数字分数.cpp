#include <stdio.h>
int main ()
{
	long long int a,b,x,i;
	scanf("%lld%lld",&a,&b);
	if(a>=b)
	{
		x=a;
		a=b;
		b=x;
	}
	x=0;
	for(i=a;i<=b;i++)
	{
		if(i%6==0||i%8==0)
		{
			x++;
		}
	}
	printf("%lld",x);
	return 0;
}
