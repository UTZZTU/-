#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int f[1000010],n;
int main ()
{
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i*=2)
	{
		for(int j=i;j<=n;j++)
		{
			f[j]=(f[j]+f[j-i])%mod;
		}
	}
	cout<<f[n];
	return 0;
}