#include <stdio.h>
int main ()
{
	long long int c[40];
	c[0]=3;
	c[1]=8;
	for(int i=2;i<40;i++)
	{
		c[i]=(c[i-1]+c[i-2])*2;
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",c[n-1]);
	}
	return 0;
}
