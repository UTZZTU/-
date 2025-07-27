#include <stdio.h>
int main ()
{
	long long int t,i,n,m,j,q,sum1,sum2;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		sum1=1;sum2=1;
		scanf("%lld%lld",&n,&m);
		if(n-m<m)
		q=n-m;
		else
		q=m;
		if(q==0)
		{
			printf("1");
		}
		else
		{
			for(j=1;j<=q;j++)
		{
			sum1*=n;
			n-=1;
		}
		for(j=1;j<=q;j++)
		{
			sum2*=j;
		}
		printf("%lld",sum1/sum2);
		}
		if(i!=t)
		printf("\n");
	}
	return 0;
}
