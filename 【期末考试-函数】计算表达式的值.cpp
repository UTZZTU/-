#include <stdio.h>
double fun(int n)
{
	double sum=0,t;
	int i;
	if(n%2==0)
	{
		for(i=2;i<=n;i+=2)
		{
			t=1.0/i;
			sum+=t;
		}
	}
	else
	{
		for(i=1;i<=n;i+=2)
		{
			t=1.0/i;
			sum+=t;
		}
	}
	return sum;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%.6f\n",fun(n));
	}
	return 0;
}
