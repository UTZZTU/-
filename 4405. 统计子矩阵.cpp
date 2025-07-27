#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[555][555];
ll n,m,k,ans;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
			f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			for(int s=1,t=1;t<=n;t++)
			{
				while(s<=t&&f[t][j]-f[s-1][j]-f[t][i-1]+f[s-1][i-1]>k)
				s++;
				if(s<=t)
				ans+=t-s+1;
			}
		}
	}
	cout<<ans;
	return 0;
}