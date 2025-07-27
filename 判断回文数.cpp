#include <stdio.h>
int main ()
{
	int n,j,k=0;
	scanf("%d",&n);
	j=n;
	while(j)
	{
		k=k*10+j%10;
		j/=10;
	}
	if(k==n)
	printf("yes");
	else
	printf("no");
	return 0;
}
