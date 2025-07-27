#include <stdio.h>
int main ()
{
	int n,sum=0;
	scanf("%d",&n);
	while(n>=5)
	{
		n-=5;
		sum++;
	}
	while(n>=4)
	{
		n-=4;
		sum++;
	}
	while(n>=3)
	{
		n-=3;
		sum++;
	}
	while(n>=2)
	{
		n-=2;
		sum++;
	}
	while(n>=1)
	{
		n-=1;
		sum++;
	}
	printf("%d",sum);
	return 0;
}
