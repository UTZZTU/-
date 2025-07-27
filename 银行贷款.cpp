#include <stdio.h>
#include <math.h>
int main ()
{
	double money,s;
	int month;
	scanf("%lf %d",&money,&month);
	if(month<=12)
	{
		s=money*pow((1+0.009),month);
	}
	else if(month>=13&&month<=24)
	{
		s=money*pow((1+0.01),month);
	}
	else if(month>=25&&month<=36)
	{
		s=money*pow((1+0.0111),month);
	}
	else
	{
		s=money*pow((1+0.012),month);
	}
	printf("%.2f",s);
	return 0;
}
