#include <stdio.h>
#include <math.h>
int main ()
{
	int n;
	double a,b,c,p,x1,x2;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		p=b*b-4*a*c;
		if(p>0)
		{
			x1=(-b+sqrt(p))/(2*a);
			x2=(-b-sqrt(p))/(2*a);
			printf("x1=%.5f;x2=%.5f\n",x1,x2);
		}
		else if(p==0)
		{
			x1=(-b)/(2*a);
			printf("x1=x2=%.5f\n",x1);
		}
		else
		{
			x1=(-b)/(2*a);
			x2=sqrt((fabs(p)))/(2*a);
			if(b!=0) 
			printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",x1,x2,x1,x2);
			else
			{
				printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",fabs(x1),x2,fabs(x1),x2);
			}
		}
	}
	return 0;
}
