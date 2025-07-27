#include <stdio.h>
int main ()
{
	int n,a[1000],i=0;
	scanf("%d",&n);
	while(n!=1)
	{
		a[i]=n;
		i++;
		if(n%2==0)
		n/=2;
		else
		n=3*n+1;
	}
	a[i]=1;
	for(i;i>=0;i--)
	printf("%d ",a[i]);
	return 0;
}