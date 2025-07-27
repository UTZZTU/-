#include <stdio.h>
double fun(double e)
{
	double s=1,w,q=1.0/3;
for(int i=1;i<=1000000;i++)
	{
		s+=q;
		if(q<e)
		break;
		q=q*(i+1)/(2*i+3);
	}
	return s;
}
int main ()
{
	double e;
	while(scanf("%lf",&e)!=EOF)
	{
		printf("%.6llf\n",2*fun(e));
	}
	return 0;
}
