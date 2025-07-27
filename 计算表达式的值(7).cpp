#include <stdio.h>
double fun(double x,double y,double z)
{
	double k;
	k=(x+y)*1.0/(x-y)+(z+y)*1.0/(z-y);
	return k;
}
int main ()
{
	double x,y,z;
	while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
	{
		printf("%.2f\n",fun(x,y,z));
	}
	return 0;
}
