#include <bits/stdc++.h>
using namespace std;
const int INF = 998244353;
typedef long long ll;
ll f[2010][2010];
ll sum=1;
ll fastpower(ll a,ll b,ll p)
{
	ll result=1;
	while(b)
	{
		if(b&1)
		result=result*a%p;
		b>>=1;
		a=a*a%p;
	}
	return result;
}
int main ()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	cout<<m;
	else
	{
		for(int i=1;i<=n;i++)
		f[i][1]=1;
		for(int i=2;i<=k+1;i++)
		f[1][i]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=k+1;j++)
			{
				if(j>i)
				f[i][j]=0;
				else if(j==i)
				f[i][j]=1;
				else
				f[i][j]=(f[i-1][j-1]%INF+f[i-1][j]%INF)%INF;
			}
		}
		sum=f[n][k+1]*m%INF;
		sum*=fastpower(m-1,k,INF);
		sum%=INF;
		cout<<sum;
	}
	return 0;
}