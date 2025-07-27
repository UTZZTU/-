#include <stdio.h>
#include <string.h>
int main ()
{
	int a[110][110],n,m,k,i,j,x,y,b,sum=0;
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x++;
		y++;
		a[x][y]=1;
		a[x-1][y]=a[x-2][y]=a[x+1][y]=a[x+2][y]=a[x][y-1]=a[x][y-2]=a[x][y+1]=a[x][y+2]=a[x-1][y-1]=a[x-1][y+1]=a[x+1][y-1]=a[x+1][y+1]=1;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		x++;
		y++;
		for(j=x-2;j<=x+2;j++)
		{
			for(b=y-2;b<=y+2;b++)
			a[j][b]=1;
		}
	}
	for(i=2;i<=n+1;i++)	
	for(j=2;j<=n+1;j++)
	{
		if(a[i][j]==0)
		sum++;
	}
	printf("%d",sum);
	return 0;
}