#include <stdio.h>
#include <math.h>
double fun(int i)
{
	double t;
	t=((2*i-1)*(2*i+1))*1.0/(4*i*i);
	return t;
}
int main ()
{
	int i,n;
	double sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			sum=0;
		for(i=1;i<=n;i++)
	{
		sum+=pow(-1,i-1)*fun(i);
	}
	printf("%.6f\n",sum);
	}
		}
		
	return 0;
}
