#include <bits/stdc++.h>
using namespace std;
int m,n,sx,sy,x,y;
int f[1010][1010];
int main ()
{
	scanf("%d%d%d%d",&m,&n,&sx,&sy);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d%d",&x,&y);
			if(x==0&&y==0)
			f[i][j]=0;
			else
			f[i][j]=(x-1)*m+y;
		}
	}
	while(1)
	{
		if(sx==0||sy==0)
		break;
		printf("%d %d\n",sx,sy);
		int p=f[sx][sy];
		if(p%m==0)
		{
			sx=p/m;
			sy=m;
		}
		else
		{
			sx=p/m+1;
			sy=p%m;
		}
	}
	return 0;
}