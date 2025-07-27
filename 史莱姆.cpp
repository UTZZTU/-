#include <stdio.h>
int main ()
{
	int n,cs=0,i;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		while(n%i==0&&n/i!=1)
		{
			n=n/i;
			cs++;
		}
	}
	printf("%d",cs+1);
	return 0;
}
