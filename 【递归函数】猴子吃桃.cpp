#include <stdio.h>
int fun(int n)
{
	if(n==1)
	return 1;
	else
	{
		return (fun(n-1)+1)*2;
	}
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
