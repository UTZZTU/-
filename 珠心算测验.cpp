#include<stdio.h>
int main ()
{
	int n,i,a[105],b[100010],j,k=0,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			b[k]=a[i]+a[j];
			k++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[i]==b[j])
			{
				sum++;
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}