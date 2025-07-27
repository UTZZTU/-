#include <stdio.h>
int main ()
{
	long long int a,b,i,sum1=1,sum2=1;
	scanf("%lld%lld",&a,&b);
	if(a>110)
	a=110;
	if(b>110)
	b=110;
	if(a>=b)
	{
		for(i=2;i<=a;i++)
	{
		sum1=sum1*i%999068070;
		
		if(i<=b)
		{
		sum2=sum2*i%999068070;
		}
	}
	}
	else
	{
		for(i=2;i<=b;i++)
	{
		sum2=sum2*i%999068070;
		if(i<=a)
		{
			sum1=sum1*i%999068070;
		}
	}
	}
	if(sum1>sum2)
	printf("a is the winner!");
	else if(sum1<sum2)
	printf("b is the winner!");
	else
	printf("There is no winner!");
	return 0;
}
