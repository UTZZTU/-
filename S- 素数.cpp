#include <stdio.h>
#include <math.h>
int fun(int n)
{
	int i;
	if(n==2||n==3)
	return 1;
	if(n%6!=1&&n%6!=5)
	return 0;
	for(i=5;i<=floor(sqrt(n));i+=6)
	{
		if(n%i==0||n%(i+2)==0)
		{
			return 0;
		}
	}
	return 1;
}
int main ()
{
	long long int m,n,t,pd=0,x;
	scanf("%lld%lld",&m,&n);
	if(m>=n)
	{
		t=m;
		m=n;
		n=t;
	}
	for(t=2;t<=m;t++)
	{
		if(m%t==0&&n%t==0)
		{
			pd=1;
			break;
		}
	}
	if(pd==1)
	{
		x=m*n;
	}
	else
	{
		x=m+n;
	}
	printf("%lld\n",x);
	if(fun(x))
	printf("YES");
	else
	printf("NO");
	return 0;
}
