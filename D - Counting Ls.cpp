#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,pre1[2010][2010],pre2[2010][2010],sum;
string s[2010];
signed main ()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1][j-1]=='o') pre1[i][j]=1;
			pre1[i][j]+=pre1[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[j-1][i-1]=='o') pre2[j][i]=1;
			pre2[j][i]+=pre2[j-1][i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1][j-1]=='o')
			{
//				cout<<i<<" "<<j<<endl;
				sum+=pre2[i-1][j]*(pre1[i][n]-pre1[i][j]);
//				cout<<sum<<endl;
				sum+=pre2[i-1][j]*(pre1[i][j-1]);
//				cout<<sum<<endl;
				sum+=(pre2[n][j]-pre2[i][j])*(pre1[i][n]-pre1[i][j]);
//				cout<<sum<<endl;
				sum+=(pre2[n][j]-pre2[i][j])*(pre1[i][j-1]);
//				cout<<sum<<endl;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}