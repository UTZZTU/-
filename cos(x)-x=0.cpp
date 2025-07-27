#include <stdio.h>
#include <math.h>
int main ()
{
	double q,h;
	scanf("%lf",&q);
	h=cos(q);
	while(h-q<=-0.000001||h-q>=0.000001)
	{
		q=h;
		h=cos(q);
	}
	printf("%.6f",h);
	return 0;
}
