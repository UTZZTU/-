#include <stdio.h>
int fun(int n)
{
	int k;
	while(n!=0)
	{
		k=n%10;
		if(k==8)
		return 1;
		else
		n/=10;
	}
	return 0;
}
int main ()
{
	int n,sum=0,i;
	scanf("%d",&n);
	for(i=8;i<=n;i++)
	{
		if(fun(i))
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}