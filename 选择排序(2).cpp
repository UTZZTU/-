#include <stdio.h>
int main ()
{
	int n,m,c[20],t,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<m;i++)
		{
			k=i;
			for(int a=i+1;a<n;a++)
			{
			if(c[k]>c[a])
			k=a;	
			}
			if(k!=i)
				{
					t=c[k];
					c[k]=c[i];
					c[i]=t;
				}
		}
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
	return 0;
}
