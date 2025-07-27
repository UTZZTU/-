#include <stdio.h>
int main ()
{
	int n,i,sum=0,c,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&c,&k);
		if(c+k<=50)
		sum++;
	}
	printf("%d",sum);
	return 0;
}