#include <stdio.h>
int main ()
{
	long long int a,n;
	long long int s=0,sum=0;
	scanf("%lld %lld",&a,&n);
	for(int i=1;i<=n;i++)
	{
		s+=a;
		a*=10;
		sum+=s;
	}
	printf("%lld",sum);
	return 0;
}
