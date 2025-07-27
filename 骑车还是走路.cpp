#include <stdio.h>
int main ()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<100)
		printf("Walk");
		else if(x==100)
		printf("All");
		else
		printf("Bike");
		if(i!=n)
		printf("\n");
	}
	return 0;
}
