#include <stdio.h>
int a;
double b;
void fun(double s)
{
	a=s;
	b=s-a;
}
int main ()
{
	double s;
	while(scanf("%lf",&s)!=EOF)
	{
		fun(s);
		printf("%d %.6f\n",a,b);
	}
	return 0;
}
