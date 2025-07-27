#include <stdio.h>
int main ()
{
	int sum=0,a[8],i;
	for(i=1;i<=7;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i]*i;
	}
	i--;
	while(a[i]==0)
	{
		i--;
	}
	sum+=a[1]*i;
	if(i==1)
	printf("1");
	else
	printf("%d",sum);
	return 0;
}