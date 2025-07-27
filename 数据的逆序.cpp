#include <stdio.h>
int main ()
{
	int n,a,w;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
		int s;
		int c[n];
		for(int i=0;i<=n-1;i++)
		{
			scanf("%d",&a);
			c[i]=a;
		}
		 w=n/2-1;
		 for(int i=0;i<=w;i++)
		 {
		 	s=c[i];
		 	c[i]=c[n-1-i];
		 	c[n-1-i]=s;
		 }
		
	for(int i=0;i<=n-2;i++)
	{
		printf("%d ",c[i]);
	}
	printf("%d",c[n-1]);
	printf("\n");
}
	}
	return 0;
}
