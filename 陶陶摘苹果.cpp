#include <stdio.h>
int main ()
{
	int a[10],i,k,sum=0;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&k);
	for(i=0;i<10;i++)
	{
		if(k+30>=a[i])
		sum++;
	}
	printf("%d",sum);
	return 0;
}