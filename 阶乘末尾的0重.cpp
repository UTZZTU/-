#include <stdio.h>
int main ()
{
	int n,t,i,j,sum,q;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
	    sum=0;
		scanf("%d",&n);
		for(j=5;j<=n;j++)
		{
			q=j;
			while(q%5==0)
			{
				q/=5;
				sum++;
			}
		}
		printf("%d",sum);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
