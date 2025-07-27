#include <stdio.h>
int main ()
{
	int t,i,a[6],sum,j,pd,c,b;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		pd=0;
		for(j=0;j<6;j++)
		{
			scanf("%d",&a[j]);
			sum+=a[j];
		}
		for(j=0;j<6;j++)
		{
			for(c=j+1;c<6;c++)
			{
				for(b=c+1;b<6;b++)
				{
					if(sum==2*(a[c]+a[j]+a[b]))
					{
						pd=1;
						break;
					}
				}
			}
		}
		if(pd==1)
		printf("yes");
		else
		printf("no");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
