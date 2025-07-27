#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int n,x,y,res,a[200010],b[200010];
int qmi(int a,int b,int c)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%c;
		a=a*a%c;
		b>>=1;
	}
	return res;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		if(a[i]<x||b[i]>y) continue;
		res++;
	}
	printf("%lld",((qmi(2,res,mod)-1)%mod+mod)%mod);
	return 0;
}