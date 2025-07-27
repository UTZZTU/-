#include<stdio.h>
int main ()
{
 long long int n,sum=0,a=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		a=a*i;
		a=a%1000000;
		sum=sum+a;
		sum=sum%1000000;
	}
	printf("%lld",sum);
 return 0;
}

