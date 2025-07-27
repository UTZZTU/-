#include<stdio.h>
int main ()
{
	int n,k=0,t;
	scanf("%d",&n);
	if(n<0)
	{
		n*=-1;
		while(n!=0)
		{
			t=n%10;
			k=k*10+t;
			n/=10;
		}
		k*=-1;
		printf("%d",k);
	}
	else if(n==0)
	printf("0");
	else
	{
		while(n!=0)
		{
			t=n%10;
			k=k*10+t;
			n/=10;
		}
		printf("%d",k);
	}
	return 0;
}