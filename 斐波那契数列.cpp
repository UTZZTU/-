#include <stdio.h>
int main ()
{
	int t,n,m,o,q;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		m=1;
		o=1;
		scanf("%d",&n);
		if(n==1)
		printf("1");
		else if(n==2)
		printf("1");
		else
		{
			for(int a=3;a<=n;a++)
			{
				q=m+o;
				m=o;
				o=q;
			}
			printf("%d",q);
		}
		if(i!=t)
		printf("\n");
	}
	return 0;
 } 
