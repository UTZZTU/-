#include <stdio.h>
#include <math.h>
int main ()
{
	int n,i;
	double sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=pow(-1,i-1)*1*1.0/i;
	}
	printf("%.4f",sum);
	return 0;
}
