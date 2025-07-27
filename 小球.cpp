#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	int r,b,c,d,e,sum;
	scanf("%d%d%d%d%d",&r,&b,&c,&d,&e);
	if(e<=c&&e<=d)
	sum=r*c+b*d;
	else if(e>=c&&e>=d)
	{
		if(r<=b)
		sum=2*r*e+d*(b-r);
		else
		sum=2*b*e+c*(r-b);
	}
	else
	{
		if(r<=b)
		sum=max(2*r*e+d*(b-r),r*c+b*d);
		else
		sum=max(r*c+b*d,2*b*e+c*(r-b));
	}
	printf("%d",sum);
	return 0;
}