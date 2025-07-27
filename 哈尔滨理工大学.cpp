#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
	int n,i,c[31],sum=0,q;
    for(i=0;i<=30;i++)
    {
    	c[i]=0;
	}
	scanf("%d",&n);
	q=n;
	for(i=30;i>=1;i--)
	{
		if(q>=pow(2,i))
		{
			q-=pow(2,i);
			c[i]=1;
		}
	}
	for(i=0;i<=30;i++)
	{
		if(c[i]==1)
		sum+=pow(2,i);
	}
	if(sum==n)
	{
		for(i=0;i<=30;i++)
		{
			if(c[i]==1)
			printf("%d ",pow(2,i));
		}
	}
	else
	printf("-1");
	return 0;
}
