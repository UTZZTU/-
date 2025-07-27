#include <stdio.h>
#define max 32
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else 
		{
			int c[max],i=0;
			while(n>0)
			{
				c[i]=n%2;
				i=i+1;
				n=n/2;
			}
			for(;i>0;i--)
			{
				printf("%d",c[i-1]);
			}
			printf("\n");
		}
	}
	return 0;
}
