#include <stdio.h>
int main ()
{
	int b,n,sum;
	while (scanf("%d",&n)!=EOF)
	{
		sum=1;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&b);
			if(b%2!=0)
			{
			sum*=b;
			}
		}printf("%d\n",sum);
	}
	return 0;
	
}
