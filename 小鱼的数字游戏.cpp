#include <stdio.h>
int main ()
{
	int n,a[105],i=0;
	while(~scanf("%d",&n))
	{
		if(n==0)
		break;
		else
		{
			a[i]=n;
			i++;
		}
	}
	i--;
	for(i;i>=0;i--)
	printf("%d ",a[i]);
	return 0;
}