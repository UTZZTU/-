#include <stdio.h>
#include <math.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(pow(n%10,3)+pow(n/10%10,3)+pow(n/100,3)==n)
	printf("YES");
	else
	printf("NO");
	return 0;
}
