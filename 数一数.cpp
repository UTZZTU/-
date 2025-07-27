#include <stdio.h>
#include <math.h>
int main ()
{
	long long int x,y,sum=0,n;
	double s;
	scanf("%lld%lld",&x,&y);
	if(x%2!=0)
	{
		sum++;
		x++;
	}
	if(y%2==0)
	{
		sum++;
		y--;
	}
	s=(y-x)*1.0/2;
	n=ceil(s);
	sum+=n;
	printf("%lld",sum);
	return 0;
}