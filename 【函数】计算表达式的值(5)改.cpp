#include <stdio.h>
int main ()
{
	double e,s,x,sum,dx;
	int i;
	while(scanf("%lf",&e)!=EOF)
	{
		sum=1;
		s=1;
		x=1;
		for(i=1;;i++)
		{
			s*=i;
			x*=(2*i+1);
			dx=s*1.0/x;
			if(dx<e)
			break;
			else
			sum+=dx;
		}
		printf("%.6f\n",sum*2);
	}
	return 0;
}
