#include <stdio.h>
int main ()
{
	int n,a;
	while(scanf("%d",&n)!=EOF)
	{
		int s=0;
		if(n==0)
		break;
		else 
		{
		int c[n];
		for(int i=0;i<=n-1;i++)
		{
			scanf("%d",&a);
			c[i]=a;
		}
		for(int i=0;i<=n-1;i++)
		{
			if(c[i]>s)
			s=c[i];
		}
		printf("%d ",s);
		for(int i=0;i<=n-1;i++)
		{
			if(c[i]==s)
			{
				printf("%d",i);
				break;
			}
		}
		printf("\n");
	}
}
	return 0;
}
