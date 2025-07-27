#include <stdio.h>
#include <math.h>
int main ()
{
	int m;
	double n,sum;
	while(scanf("%lf",&n)!=EOF)
	{
		sum=n;
		scanf("%d",&m);
		for(int i=1;i<m;i++)
		{
		n=sqrt(n);
		sum+=n;
		}printf("%.2f",sum);
	}
	return 0;
}
