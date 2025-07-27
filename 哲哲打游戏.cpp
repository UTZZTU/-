#include <stdio.h>
int a[1000][1000],b[1000];
int main ()
{
	int n,m,i,k,j,w=1,r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&k,&r);
		if(k==0)
		{
			w=a[w][r];
		}
		else if(k==1)
		{
			b[r]=w;
			printf("%d\n",w);
		}
		else if(k==2)
		{
			w=b[r];
		}
	}
	printf("%d",w);
	return 0;
}