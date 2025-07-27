#include <stdio.h>
int main ()
{
	int n,t;
	scanf("%d%d",&n,&t);
	if(n<t)
	printf("0");
	else
	printf("%d",n-t);
	return 0;
}