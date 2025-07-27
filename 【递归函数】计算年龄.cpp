#include <stdio.h>
int fun(int n)
{
	int a1=18;
	if(n==1)
	return a1;
	for(int i=1;i<=n-1;i++)
	{
		a1-=2;
	}
	return a1;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",fun(n));
	}
	return 0;
}
