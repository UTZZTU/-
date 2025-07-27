#include <stdio.h>
int main ()
{
	int n,m,a[100][100],b[100],i,j,sum=0,max=0,min=100,zh;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
	    zh=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				sum++;
				zh++;
			}
		}
		b[i]=zh;
		if(b[i]>max)
		max=b[i];
		if(b[i]<min)
		min=b[i];
	}
	printf("%d ",sum);
	for(i=0;i<n;i++)
	{
		if(b[i]==max)
		{
			printf("%d ",i+1);
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(b[i]==min)
		{
			printf("%d",i+1);
			break;
		}
	}
	return 0;
}
