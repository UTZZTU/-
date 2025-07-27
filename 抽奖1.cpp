#include <stdio.h>
int main ()
{
	int n,i,k,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(k==a[i])
		{
			printf("%d",i+1);
			return 0;
		}
	}
	printf("0");
	return 0;
}