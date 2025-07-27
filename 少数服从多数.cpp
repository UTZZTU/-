#include <stdio.h>
int main ()
{
	int n,sum1=0,sum2=0,i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k==0)
		sum2++;
		else
		sum1++;
	}
	if(sum1>sum2)
	printf("Yes");
	else
	printf("No");
}