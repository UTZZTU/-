#include <stdio.h>
int main ()
{
	int m,n,i,sum=0;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++)
	{
		if(i%15==0)
		sum+=i;
	}
	printf("%d",sum);
	return 0;
}
