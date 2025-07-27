#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],t,f[15][15],cnt;
void dfs(int x,int y)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
			}
		}
		int res1=0,res2=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k1=i;k1<=n;k1++)
				{
					for(int k2=j;k2<=m;k2++)
					{
						if(f[k1][k2]-f[i-1][k2]-f[k1][j-1]+f[i-1][j-1]==0||f[k1][k2]-f[i-1][k2]-f[k1][j-1]+f[i-1][j-1]==(k1-i+1)*(k2-j+1))
						res1++;
						else res2++;
					}
				}
			}
		}
		if(res1==res2)
		{
			printf("%d: %d %d\n",cnt++,res1,res2);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
			printf("\n\n\n");
		}
		return;
	}
	a[x][y]=0;
	if(y+1<=m)
	{
		dfs(x,y+1);
	}
	else dfs(x+1,1);
	a[x][y]=1;
	if(y+1<=m)
	{
		dfs(x,y+1);
	}
	else dfs(x+1,1);
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=1;
		scanf("%d%d",&n,&m);
		dfs(1,1);
	}
	return 0;
}