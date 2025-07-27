#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n%6==0)
	printf("%d",n/6);
	else
	printf("%d",n/6+1);
	return 0;
}