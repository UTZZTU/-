#include <stdio.h>
int main ()
{
	int n,i,min=1000,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k<min)
		min=k;
	}
	printf("%d",min);
	return 0;
}