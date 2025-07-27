#include <stdio.h>
#include <math.h>
int main ()
{
	int n;
	double w=0;
	scanf("%d",&n);
	while(n--)
	{
		double xi,yi,d,t;
		int ri;
		scanf("%lf %lf %d",&xi,&yi,&ri);
		d=sqrt(xi*xi+yi*yi);
		t=d/50;
		w+=2*t+1.5*ri;
	}
	int j;
	j=ceil(w);
	printf("%d",j);
	return 0;
}
