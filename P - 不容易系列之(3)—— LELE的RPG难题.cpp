#include <stdio.h>
int main ()
{
	long long int n,c[50];
	 c[0]=3,c[1]=6,c[2]=6;
	for(int i=3;i<50;i++)
	{
		c[i]=c[i-1]+2*c[i-2];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",c[n-1]);
	}
	return 0;
}
