#include <stdio.h>
long long int fun(long long int a,long long int b)
{
	long long int c;
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()
{
	int i,n;
	long long x=1,y,sum=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
{
	scanf("%lld",&y);
	sum=x/fun(x,y)*y;
	x=sum;	
}
	printf("%lld",sum);
	return 0;
}