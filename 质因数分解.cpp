#include <stdio.h>
#include <math.h>
int fun(int n)
{
	if(n==2||n==3)
	return 1;
	if(n%6!=5&&n%6!=1)
	return 0;
	for(int i=5;i<=floor(sqrt(n));i+=6)
	{
		if(n%i==0||n%(i+2)==0)
		return 0;
	}
	return 1;
}
int main ()
{
	int n,i,m;
	scanf("%d",&n);
	for(i=floor(sqrt(n));i>=2;i--)
	{
		if(n%i==0)
		{
			m=n/i;
			if(fun(i)==1&&fun(m)==1)
			{
				printf("%d",m);
				break;
			}
		}
	}
	return 0;
}