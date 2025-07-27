#include <stdio.h>
int main ()
{
	double a,sum=0;
	for(int i=1;i<=12;i++)
	{
		scanf("%lf",&a);
		sum+=a;
	}
	printf("$%.2f",sum/12);
	return 0;
}
