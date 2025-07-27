#include <stdio.h>
int main ()
{
	int t,s;
	while(scanf("%d",&t)!=EOF)
	{
		s=0;
		for(int i=2;i<=t;i++)
		{
			s=(s+2)%i;
		}
		printf("%d\n",s+1);
	}
	return 0;
}
