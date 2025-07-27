#include <stdio.h>
int main ()
{
	int n,i,x;
	long long int sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x%4==0||x%7==0)
		sum+=x;
	}
	printf("%lld",sum);
	return 0;
}
