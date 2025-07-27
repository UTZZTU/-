#include <stdio.h>
int main ()
{
	int n,i,k,a1=0,a2=0,a3=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a1+=k/100;
		k%=100;
		a2+=k/10;
		k%=10;
		a3+=k;
	}
	printf("%d\n%d\n%d",a1,a2,a3);
	return 0;
}