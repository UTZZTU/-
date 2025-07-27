#include <stdio.h>
int main ()
{
	int n,max=-99999999,c[100];
	scanf("%d",&n);
	for(int i=0;i<n*n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]>max)
		max=c[i];
	}
	printf("%d ",max);
	for(int i=0;i<n*n;i++)
	{
		if(c[i]==max)
		{
			printf("%d %d",i/n,i%n);
			break;
		}
	}
	return 0;
}
