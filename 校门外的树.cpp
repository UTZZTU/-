#include <stdio.h>
int main ()
{
	int c[10002];
	int L,M,n,m,w=0;
	scanf("%d%d",&L,&M);
	for(int i=0;i<=L;i++)
	{
		c[i]=1;
	}
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d",&n,&m);
		for(int a=n;a<=m;a++)
		{
			c[a]=0;
		}
	}
	for(int i=0;i<=L;i++)
	{
		if(c[i]!=0)
		w++;
	}
	printf("%d",w);
	return 0;
}
