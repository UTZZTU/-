#include <stdio.h>
int main ()
{
	int n,c[100],x,s,w,t,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		w=0;
		s=0;
		scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	scanf("%d",&x);
	for(int i=0;i<n;i++)
	{
		if(c[i]==x)
		{
				printf("Find ");
				break;
		}
		else w++;
	}
	if(w==n)
	printf("No find ");
	for(int i=0;i<n;i++)
	{
		if(c[i]<x)
		s++;
	}
	printf("%d",s);
	if(j!=t)
	printf("\n");
	}
	return 0;
}
