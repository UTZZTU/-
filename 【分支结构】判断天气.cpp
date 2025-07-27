#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n<=5)
	printf("cold");
	else if(n>=6&&n<=25)
	printf("warm");
	else
	printf("hot");
	return 0;
}
