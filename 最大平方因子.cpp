#include <stdio.h>
int main ()
{
	int n,i=1,max;
	scanf("%d",&n);
	while(i*i<=n)
	{
		if(n%(i*i)==0)
		{
			max=i*i;
		}
		i++;
	}
	printf("%d",max);
	return 0;
}