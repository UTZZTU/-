#include <stdio.h>
int main ()
{
	int n,t,sum=0,k,i;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(t>=k)
		sum++;
	}
	printf("%d",sum);
}