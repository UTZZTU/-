#include <stdio.h>
int fun(int n,int k)
{
	if(n<=k+1||(n+k)%2==1&&(n-k)%2==1)
	return 1;
	else
	return fun((n+k)/2,k)+fun((n-k)/2,k);
}
int main ()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",fun(n,k));
	return 0;
}
