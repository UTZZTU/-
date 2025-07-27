#include <stdio.h>
int main ()
{
	int n,m,sum=0,i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		sum+=i;
	}
	m=sum;
	sum=0;
	for(i=1;i<m;i++)
	{
		if(m%i==0)
		sum+=i;
	}
	if(sum==n)
	printf("%d-%d",n,m);
	else
	printf("No");
	return 0;
}
