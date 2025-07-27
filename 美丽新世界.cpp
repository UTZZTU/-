#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[110],p,a,n;
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
signed main ()
{
	cin>>f[1]>>f[2]>>p>>a>>n;
	for(int i=3;i<=n;i++)
	{
		int u=qmi(f[i-1],f[i-2])%p+1;
		f[i]=floor((double)log(u)*1.0/(double)log(2))+a;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",f[i]);
	}
	return 0;
}