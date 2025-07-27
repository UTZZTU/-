#include <stdio.h>
#include <string.h>
int main ()
{
	int a[305],n1,n2,n3,i,j,k,sum,max=0;
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&n1,&n2,&n3);
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			for(k=1;k<=n3;k++)
			{
				sum=0;
				sum=i+j+k;
				a[sum]++;
			}
		}
	}
	for(i=3;i<=n1+n2+n3;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	for(i=3;i<=n1+n2+n3;i++)
	{
		if(a[i]==max)
		printf("%d ",i);
	}
	return 0;
}
