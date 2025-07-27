#include <stdio.h>
int main ()
{
	int n,m,k,i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=k;i<=n;i+=m)
	printf("%d ",i);
	return 0;
}