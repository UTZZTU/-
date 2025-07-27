#include <stdio.h>
int main ()
{
	int n,i,sum,k;
	scanf("%d",&n);
	sum=1;
	k=1;
	for(i=2;i<=n;i++)
	{
		k+=i;
		sum+=k;
	}
	printf("%d",sum);
	return 0;
}