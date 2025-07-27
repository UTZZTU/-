#include <stdio.h>
#include <math.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n>=1&&n<=32)
	printf("Golden Medal");
	else if(n>32&&n<=96)
	printf("Silver Medal");
	else if(n>96&&n<=192)
	printf("Bronze Medal");
	else
	printf("Honorable Mention");
	return 0;
}
