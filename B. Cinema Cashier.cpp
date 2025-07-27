#include <bits/stdc++.h>
using namespace std;
int n,k,dp[100][100],f[1005];
void solve()
{
	cin>>n>>k;
	int xc=(k+1)/2,yc=(k+1)/2;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		int minn=0x3f3f3f3f,hc=-1,lc=-1;
		for(int j=1;j<=k;j++)
		{
			for(int l=1;l<=k-f[i]+1;l++)
			{
				int flag=1;
				int res=0;
				for(int r=l;r<=l+f[i]-1;r++)
				{
					if(dp[j][r])
					{
						flag=0;
						break;
					}
					else
					{
						res+=abs(j-xc)+abs(r-yc);
					}
				}
				if(flag&&res<minn)
				{
					minn=res;
					hc=j;
					lc=l;
				}
			}
		}
		if(minn==0x3f3f3f3f) cout<<-1<<endl;
		else
		{
			cout<<hc<<" "<<lc<<" "<<lc+f[i]-1<<endl;
			for(int j=lc;j<=lc+f[i]-1;j++)
			{
				dp[hc][j]=1;
			}
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}