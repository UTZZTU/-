#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll n,f[1000010];
int main ()
{
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	else if(n==2)
	{
		cout<<2;
		return 0;
	}
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1]*(i+2)%MOD;
	}
	cout<<f[n];
	return 0;
}