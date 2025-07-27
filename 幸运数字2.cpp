#include <stdio.h>
int fun(int n)
{
	int c;
	while(n!=0)
	{
		c=n%10;
		if(c==7)
		return 1;
		n/=10;
	}
	return 0;
}
int main ()
{
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=7;i<=n;i++)
	{
		if(i%7==0||fun(i)==1)
		sum+=i;
	}
	printf("%d",sum);
	return 0;
}