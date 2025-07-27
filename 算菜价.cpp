#include <stdio.h>
int main ()
{
	double n;
	double s,sum=0,t=0;
	while(~scanf("%lf %lf",&n,&s))
	{
		sum+=n*s;
	}
	while(sum>=1)
	{
		sum-=1;
		t+=1;
	}
	while(sum>=0.1)
	{
		sum-=0.1;
		t+=0.1;
	}
	if(sum>=0.05)
	{
		t+=0.1;
	}
	printf("%.1f",t);
	return 0;
}