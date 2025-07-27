#include <stdio.h>
int fun(int n)
{
	while(n!=0)
	{
		if(n%10!=4&&n%10!=7)
		{
			return 0;
		}
		n/=10;
	}
	return 1;
}
int main ()
{
	int a[1005],n,i;
	for(i=1;i<=1000;i++)
	{
		a[i]=fun(i);
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0&&a[i]==1)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}