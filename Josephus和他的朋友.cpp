#include <stdio.h>
#include <string.h>
int main ()
{
	int n,m,c[500],cn,i,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
		break;
		else
		{
			memset(c,1,sizeof(c));
			cn=0;
			p=0;
			i=-1;
			while(cn<n-1)
			{
				i=i+1;
				if(i==n)
				i=0;
				if(c[i]!=0)
				{
					p++;
					if(p==m)
					{
						c[i]=0;
						p=0;
						cn++;
					}
				}
				
			}
			for(i=0;i<n;i++)
			{
				if(c[i]!=0)
				{
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
	return 0;
}
