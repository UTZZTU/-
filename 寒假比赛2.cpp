#include <stdio.h>
int main ()
{
	int n,a[100000],i,sum=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	printf("1");
	else
	{
		for(i=0;i<n-1;i++)
	{
		sum=1;
		while(a[i+1]==a[i])
		{
			sum++;
			i++;
		}
		if(sum>max)
		max=sum;
	}
	printf("%d",max);
	}
	return 0;
}
