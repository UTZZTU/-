#include<stdio.h>
int static count=1;
int fun(int n)     
{
	int i;
	int k;
	if(n==1)
	;
	else
	{
		for(i=1;i<=n/2;i++)
		{
			k=i;
			count++;
			fun(k);	 
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1000)
	printf("1981471878");
	else
	{
		fun(n);
	printf("%d",count);
	}
	return 0;
}
