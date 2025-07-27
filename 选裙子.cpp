#include <stdio.h>
int main ()
{
	int n,i,x,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum+=x;
	}
	if(sum%n==0)
	printf("%d",n);
	else
	printf("%d",sum%n);
	return 0;
}
