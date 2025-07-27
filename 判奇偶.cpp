#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n%2==0)
	n/=2;
	else
	n*=2;
	printf("%d",n);
	return 0;
}