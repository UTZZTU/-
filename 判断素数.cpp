#include <stdio.h>
#include <math.h>
int fun(int n)
{
	if(n==1)
	return 0;
	if(n==2||n==3)
	return 1;
	else if(n%6!=1&&n%6!=5)
	return 0;
	else 
	{
		for(int i=5;i<floor(sqrt(n));i+=6)
		{
			if(n%i==0||n%(i+2)==0)
			return 0;
		}
		return 1;
	}
}
int main ()
{
	int n,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		if(fun(k))
		printf("Yes\n");
		else
		printf("No\n");
	}
}