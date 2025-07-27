#include <stdio.h>
int main ()
{
	int n;
	int c[20],b[20];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else 
		{
			for(int i=0;i<n;i++)
			{
				scanf("%d",&c[i]);
			}
			int w=0;
			for(int q=1;q<=n;q++)
			{
				
				for(int i=0;i<n;i++)
				{
					if(i+w>=n)
					b[(i+w)%n]=c[i];
					else b[i+w]=c[i];
				}
				for(int i=0;i<n-1;i++)
				{
					printf("%d ",b[i]);
				}
				printf("%d",b[n-1]);
				printf("\n");
				w++;
			}
		}
	}
	return 0;
}
