#include <stdio.h>
int main ()
{
	int n,i,j,k;
	scanf("%d",&n);
	k=0;
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<n;j++)
			{
				k++;
				printf("%d ",k);
			}
			k++;
			printf("%d",k);
			if(i!=n)
			printf("\n");
		}
		else
		{
			for(j=1;j<n;j++)
			{
				printf("%d ",k+n+1-j);
			}
			printf("%d",k+n+1-j);
			if(i!=n)
			printf("\n");
			k+=n;
		}
	}
	return 0;
}
