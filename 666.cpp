#include <stdio.h>
#include <math.h>
int main ()
{
	double a,x1=1,x2,w,t;
	scanf("%lf",&a);
	w=pow(10,-8);
    for(int i=1;i<=10000;i++)
    {
    	x2=1.0/2*(x1+a*1.0/x1);
    	if(fabs(x1-x2)<w)
    	break;
    	x1=x2;
	}
	printf("%.6f",x2);
	return 0;
}
