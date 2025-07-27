#include <stdio.h>
int main ()
{
	int n,sum=1,a=0;
		int c[9999];
	scanf("%d",&n);
	while(a<=n-1)
	{
		int s;
		scanf("%d",&s);
		c[a]=s;
		a++;
	}
	for(int i=0;i<=n-1;i++)
	{
		if(c[i]%2==1)
		{
		sum*=c[i];
		}
	}printf("%d\n",sum);

	return 0;
	
}
