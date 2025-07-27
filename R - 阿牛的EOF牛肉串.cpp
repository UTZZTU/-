#include <stdio.h>
#include <math.h>
int fun(int a,int b)
{
	long long int a1=1,a2=1,a3=1,a4=a,a5,i;
	if(b==0)
	return a3;
	else
	{
		for(i=1;i<=b;i++)
		{
			a1*=i;
		}
		for(i=1;i<=b;i++)
		{
			a2*=a4;
			a4--;
		}
		a5=a2/a1;
		return a5;
	}
}
int main ()
{
	long long int n,s,c,b,q,d,i;
	double a;
	while(scanf("%lld",&n)!=EOF)
	{
		s=0;
		if(n==1)
		printf("3\n");
		else
		{
			s+=pow(2,n);
			a=n*1.0/2;
			c=ceil(a);
			for(i=1;i<=c;i++)
			{
			  q=n-i+1;
			  if(q-i<i)
			  d=q-i;
			  else  d=i;
			  b=fun(q,d)*pow(2,n-i);
			  s+=b;
			}
			printf("%lld\n",s);
		}
	}
	return 0;
 } 
