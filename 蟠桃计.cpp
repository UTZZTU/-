#include <stdio.h>
int main ()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		
		int s,a=1;
		for (int i=1;i<n;i++)
		{
			a=2*(a+1);
		}
		printf("%d\n",a);
	}
	return 0;
}
