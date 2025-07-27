#include <bits/stdc++.h>
using namespace std;
int n,w[15][15],dp[30][15][15];
int main ()
{
	scanf("%d",&n);
	int a,b,c;
	while(cin>>a>>b>>c, a||b||c) w[a][b]=c;
	for(int k=2;k<=2*n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int p1=k-i,p2=k-j;
				if(p1>=1&&p1<=n&&p2>=1&&p2<=n)
				{
					int &x=dp[k][i][j];
					int t=w[i][p1];
					if(i!=j) t+=w[j][p2];
					x=max(x,dp[k-1][i-1][j-1]+t);
					x=max(x,dp[k-1][i-1][j]+t);
					x=max(x,dp[k-1][i][j-1]+t);
					x=max(x,dp[k-1][i][j]+t);
				}
			}
		}
	}
	printf("%d",dp[2*n][n][n]);
	return 0;
}