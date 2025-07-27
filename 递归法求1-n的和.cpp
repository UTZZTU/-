#include <stdio.h>
int fun(int n)
{
	int s=0;
	for(int i=1;i<=n;i++)
	{
		s+=i;
	}
	return s;
}
int main ()
{
	int n;
	scanf("%d",&n);
	printf("%d",fun(n));
	return 0;
}
