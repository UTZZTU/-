#include <stdio.h>
int main ()
{
	long long int a[51],n,i,j;
	a[1]=0;
	a[2]=1;
	for(i=3;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	while(scanf("%lld",&n)!=EOF)
	{
		if(n==-1)
		break;
		else
		{
			printf("%lld\n",a[n]);
		}
	}
}
