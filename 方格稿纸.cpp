#include <stdio.h>
#include <math.h>
int main ()
{
	int n,m,i,j,a[305][305],x=2,w,b,sum=0,white[305][305],black[305][305];
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			white[i][j]=white[i-1][j]+white[i][j-1]-white[i-1][j-1]+(a[i][j]?0:1);
            black[i][j]=black[i-1][j]+black[i][j-1]-black[i-1][j-1]+(a[i][j]?1:0);
		}
	}
	while(x<=n&&x<=m)
	{
		for(i=x;i<=n;i++)
		{
			for(j=x;j<=m;j++)
			{
				w=white[i][j]-white[i-x][j]-white[i][j-x]+white[i-x][j-x];
                b=black[i][j]-black[i-x][j]-black[i][j-x]+black[i-x][j-x];
                if(w-b==0||w-b==-1||w-b==1)
                sum++;
			}
		}
		x++;
	}
	printf("%d",sum);
	return 0;
}
