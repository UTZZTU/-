#include <stdio.h>
int main ()
{
	int n,k,a,w=0;
	scanf("%d %d",&n,&k);
	int c[n];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&a);
		c[i]=a;
	}

	for(int b=0;b<=n-1;b++)
	{
		int sum=0;
		for(int t=b;t<=n-1;t++)
		{
			sum+=c[t];
			if(sum>=k)
			{
			w=w+n-1-t;
			break;
		    }
		}
	}
	printf("%d",w);

	return 0;
}
