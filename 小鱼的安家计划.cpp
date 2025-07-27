#include <stdio.h>
int main ()
{
	double s;
	scanf("%lf",&s);
	if(s<15)
	printf("cold");
	else if(s>25)
	printf("hot");
	else
	printf("home");
	return 0;
}