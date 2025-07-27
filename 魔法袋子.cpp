#include <stdio.h>
int main ()
{
	int n,r,i,sum=0,x;
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<=r)
		sum++;
	}
	printf("%d",sum);
	return 0;
}
