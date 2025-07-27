#include <stdio.h>
int main ()
{
	int t,n;
	long long int s;
	scanf("%d",&t);
for(int i=1;i<=t;i++)
	{
		s=1;
		scanf("%d",&n);
		for(int a=1;a<=n;a++)
		{
			s=s*a;
		}
		printf("%lld",s);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
