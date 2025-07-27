#include <stdio.h>
#include <math.h>
int main ()
{
	int m,n,i;
	long long sum=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	{
		sum+=pow(2,i);
	}
	sum*=m;
	printf("%lld",sum);
	return 0;
}