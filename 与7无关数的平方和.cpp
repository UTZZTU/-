#include <stdio.h>
int fun(int n)
{
	int k;
	while(n!=0)
	{
		k=n%10;
		if(k==7)
		return 0;
		n/=10;
	}
	return 1;
}
int main ()
{
	int n,i,j,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%7!=0&&fun(i)==1)
		{
			sum+=i*i;
		}
	}
	printf("%d",sum);
	return 0;
}