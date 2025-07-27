#include <bits/stdc++.h>
using namespace std;
int n,m,t,r1,c1,r2,c2,f[110][110],res;
int main ()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		for(int i=r1;i<=r2;i++)
		{
			for(int j=c1;j<=c2;j++)
			{
				f[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!f[i][j]) res++;
		}
	}
	printf("%d",res);
	return 0;
}
//蓝桥杯模拟赛2023-A