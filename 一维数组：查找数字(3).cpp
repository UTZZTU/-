#include <stdio.h>
int main ()
{
	int n,c[100],x,s=0,w=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	scanf("%d",&x);
	for(int i=0;i<10;i++)
	{
		if(c[i]==x)
		{
				printf("Find ");
				break;
		}
	
		else w++;
	}
	if(w==10)
	printf("No find ");
	for(int i=0;i<n;i++)
	{
		if(c[i]>x)
		s++;
	}
	printf("%d",s);
	return 0;
}
