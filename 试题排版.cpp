#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll n,f[5010][5010];
ll work(ll m,ll n) 
{
	if(m>n)
	{
		return work(n,n); 
	}
	if(n==0&&m==0)return 1;
	if(m==0)return 0; 
	return (work(m,n-m)%MOD +work(m-1,n)%MOD)%MOD; 
}
int main()
{
	cin>>n;
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i>j)
			f[i][j]=f[j][j]%MOD;
			else if(i==0&&j==0)
			f[i][j]=1;
			else if(i==0)
			f[i][j]=0;
			else
			f[i][j]=(f[i][j-i]+f[i-1][j])%MOD;
		}
	}
	cout<<f[n][n]<<endl;
return 0;
 
}