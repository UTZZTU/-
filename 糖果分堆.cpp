#include <stdio.h>
int main ()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(n%a==0)
	printf("%d",n/a);
	else
	printf("%d",n/b);
	return 0;
}