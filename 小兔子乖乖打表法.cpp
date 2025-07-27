#include <stdio.h>
int main ()
{
	long long int c[45];
	int i,n;
	c[0]=1;
	c[1]=1;
	for(i=2;i<45;i++)
	{
		c[i]=c[i-1]+c[i-2];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",c[n-1]);
	}
	return 0;
}
