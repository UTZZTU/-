#include <stdio.h>
int gcd(int m,int n)
{
	int t,i,sum;
	if(m>n)
	{
		t=m;
		m=n;
		n=t;
	}
	for(i=1;i<=m;i++)
	{
		if(m%i==0&&n%i==0)
		sum=i;
	}
	return sum;
}
int main ()
{
	int m,n;
	long long t;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		t=gcd(m,n);
		printf("%lld %lld\n",t,n*m/t);
	}
	return 0;
}
