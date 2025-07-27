#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,y,r,b[210],dp[110],f[210][20010],ff[210];
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(f,-1,sizeof(f));
		scanf("%lld%lld%lld%lld",&n,&x,&y,&r);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
		}
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				for(int j=x;j<=100;j++)
				{
					dp[j]=max(dp[j],dp[j-x]+x);
				}
			}
			else
			{
				for(int j=y;j<=100;j++)
				{
					dp[j]=max(dp[j],dp[j-y]+y);
				}
			}
		}
//		for(int i=1;i<=100;i++)
//		{
//			cout<<dp[i]<<endl;
//		}
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			ff[i]=ff[i-1]+dp[b[i]];
		}
		if(ff[n]<r)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=ff[i];j++)
			{
//				f[i][j]=f[i-1][j];
				if(f[i-1][j]!=-1)
				f[i][j]=max(f[i][j],f[i-1][j]+b[i]*b[i]);
//				else if(j==1)
//				{
//					f[i][j]=f[i-1][j-]
//				}
				for(int k=2;k<=b[i];k++)
				{
					if(dp[k]>j) break;
					else
					{
						if(f[i-1][j-dp[k]]!=-1)
						f[i][j]=max(f[i][j],f[i-1][j-dp[k]]+(b[i]-dp[k])*(b[i]-dp[k]));
					}
				}
//				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=r;j++)
			{
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<f[n][r]<<endl;
	}
	return 0;
}