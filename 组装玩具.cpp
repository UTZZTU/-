#include <stdio.h>
#include <string.h>
int main ()
{
	int n,m,i,j,a[100010],b[100010],c[100010],d[100010],min=1000000,sum=0,max=0;
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[j]);
	}
	for(i=0;i<n;i++)
	{
		c[i]=a[i]/b[i];
		if(c[i]<min)
		min=c[i];
		if(c[i]>max)
		max=c[i];
	}
	sum+=min;
	for(i=0;i<n;i++)
	{
		d[c[i]]+=b[i]-(a[i]%b[i]);
		for(j=c[i]+1;j<=max;j++)
		{
			d[j]+=b[i];
		}
	}
	for(i=min;i<=max;i++)
	{
		m-=d[i];
		if(m<0)
		break;
		else
		sum++;
	}
	printf("%d",sum);
	return 0;
}
