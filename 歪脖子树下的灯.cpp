#include <stdio.h>
#include <math.h>
double fun(int a,int b)
{
	double m=1,n=1,i,q;
	if(b==0)
	return 1;
	else
	{
		for(i=1;i<=b;i++)
		{
			m*=a;
			a--;
		}
		for(i=1;i<=b;i++)
		{
			n*=i;
		}
		q=m/n;
	}
	return q;
}
int main ()
{
	int t,n,r,i,j;
	double p,sum,gl;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d %lf",&n,&p);
		for(j=1;j<=n;j++)
		{
			if(j%2==1)
			{
				r=n-j;
				if(j>=r)
				{
					sum+=fun(n,r)*pow(p,j)*pow((1-p),r);
				}
				else
				{
					sum+=fun(n,j)*pow(p,j)*pow((1-p),r);
				}
			}
		}
		if(sum!=0)
			printf("%lf",sum);
			else printf("0");
			if(i!=t)
			printf("\n");
	}
	return 0;
}
