#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n%5==0&&n%8==0)
	printf("luck");
	else if(n%5==0||n%8==0)
	printf("good");
	else
	printf("common");
	return 0;
}
