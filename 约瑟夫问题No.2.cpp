#include <stdio.h>
int main ()
{
	int n,p,m;
	while(scanf("%d%d%d",&n,&p,&m)!=EOF)
	{
		if(n==0&&p==0&&m==0)
		break;
		else
		{
			int c[300];
			for(int a=0;a<n;a++)
			{
				c[a]=1;
			}
			int i=p-2,pm=0,cn=0;
			while(cn<n-1)
			{
				i=i+1;
				if(i==n)
				i=0;
				if(c[i]!=0)
				{
					pm++;
					if(pm==m)
					{
						c[i]=0;
						cn++;
						pm=0;
						printf("%d,",i+1);
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(c[i]!=0)
				{
					printf("%d",i+1);
					printf("\n");
					break;
				}
			}
			
		}
	}
	return 0;
}
