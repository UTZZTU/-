#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7, M = 8192, N = 5010;
int a[N],f[2][M],res,n;
bool is_prime(int x)
{
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<M;j++)
		{
			f[i&1][j]=f[(i-1)&1][j];
			if((j^a[i])<M)
			{
				f[i&1][j]+=f[(i-1)&1][j^a[i]];
				f[i&1][j]%=MOD;
			}
		}
	}
	for(int i=2;i<M;i++)
	{
		if(is_prime(i))
		{
			res+=f[n&1][i];
			res%=MOD;
		}
	}
	cout<<res;
	return 0;
}