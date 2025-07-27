#include <stdio.h>
int main ()
{
	int n,a[1000],sum=0,i,k;
	scanf("%d",&n);
	k=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			a[k]=i;
			sum+=i;
			k++;
		}
	}
	if(sum==n)
	{
		printf("Yes,its factors are ");
		for(i=0;i<k-1;i++)
		printf("%d ",a[i]);
		printf("%d",a[i]);
	}
	else
	printf("No");
	return 0;
}
