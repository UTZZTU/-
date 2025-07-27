#include <stdio.h>
int main ()
{
	int sum=0,n;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n&1)
		n=3*n+1;
		else
		n/=2;
		sum++;
	}
	printf("%d",sum);
	return 0;
}