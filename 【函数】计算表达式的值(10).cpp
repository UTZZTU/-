#include <stdio.h>
double fun(double s)
{
	int i;
	double sum=0,t=1;
	for(i=1;;i++)
	{
		if(t>s)
		{
			sum+=t;
		}
		else break;
		t*=i*1.0/(2*i+1);
	}
	return  2*sum;
}
int main ()
{
	double s;
	while(scanf("%lf",&s)!=EOF)
	{
		printf("%.6f\n",fun(s));
	}
	return 0;
}
