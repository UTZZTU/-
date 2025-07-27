#include <stdio.h>
#include <math.h>
int main ()
{
	double s,q;
	int n,t;
	while(~scanf("%lf %d",&s,&n))
	{
		q=s*n*38;
	t=floor(q);
	t/=100;
	t*=100;
	printf("%d\n",t);
	}
}