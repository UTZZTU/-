#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n<=155)
	printf("low");
	else if(n>=156&&n<=175)
	printf("moderate");
	else
	printf("high");
	return 0;
}
