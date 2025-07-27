#include <stdio.h>
#include <math.h>
const double PI=4*atan(1.0);
int main ()
{
	int n,i,j;
	double x,y,d,s,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x,&y);
		s=PI*(x*x+y*y)/2;
		r=s/50;
		j=ceil(r);
	   printf("Property %d: This property will begin eroding in year %d.\n",i,j);
	   if(i==n)
	   printf("END OF OUTPUT.");
	}
	return 0;
 } 
