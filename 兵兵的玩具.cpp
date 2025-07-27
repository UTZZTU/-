#include <stdio.h>
#include <math.h>
const double PI=4*atan(1.0);
int main ()
{
	double n;
	while(scanf("%lf",&n)!=EOF)
	{
		printf("%.6f\n",4.0/3*PI*pow(n*1.0/2,3));
	}
	return 0;
}
