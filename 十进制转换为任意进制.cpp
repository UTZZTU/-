#include <stdio.h>
int main ()
{
	int n,r,c[32],i;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		i=0;
		if(n==0)
		printf("0\n");
		else
		{
			while(n!=0)
			{
				c[i]=n%r;
				n/=r;
				i++;
			}
			for(i=i-1;i>=0;i--)
			{
				if(c[i]<10)
				printf("%d",c[i]);
				else
				{
					printf("%c",c[i]-10+'A');
				}
			}
			printf("\n");
		}
	}
	return 0;
}
