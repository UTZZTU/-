#include <stdio.h>
int main ()
{
	int c[100],n,x,i,q1,q2;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		scanf("%d",&x);
		if(x>=c[0])
		{
			printf("%d ",x);
			for(i=0;i<n-1;i++)
			{
				printf("%d ",c[i]);
			}
			printf("%d",c[n-1]);
			printf("\n");
		}
		else if(x<=c[n-1])
		{
			for(i=0;i<n;i++)
			{
				printf("%d ",c[i]);
			}
			printf("%d",x);
			printf("\n");
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(c[i]>=x&&c[i+1]<=x)
				{
					q1=i;
					q2=i+1;
					break;
				}
			}
			for(i=0;i<=q1;i++)
			{
				printf("%d ",c[i]);
			}
			printf("%d ",x);
			for(i=q2;i<n-1;i++)
			{
				printf("%d ",c[i]);
			}
			printf("%d",c[n-1]);
			printf("\n");
		}
	}
	return 0;
}
