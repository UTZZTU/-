#include <stdio.h>
int main ()
{
	double a,q,h;
	scanf("%lf",&a);
	q=1;
	h=0.5*(q+a*1.0/q);
	while(h-q<=-0.00001||h-q>=0.00001)
	{
		q=h;
		h=0.5*(q+a*1.0/q);
	}
	printf("The square root of %.2f is %.5f",a,h);
	return 0;
}
