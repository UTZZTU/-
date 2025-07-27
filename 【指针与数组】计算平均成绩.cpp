#include <stdio.h>
double fun(int *p,int n)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=p[i];
	}
	sum=sum*1.0/n;
	return sum;
}
int main ()
{
	int n,c[100],*p;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		p=c;
		printf("%.4f\n",fun(p,n));
	}
	return 0;
}
