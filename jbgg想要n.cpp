#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 DLL;
ll f[1000010],n,m,p;
int lenth(ll x)
{
	int res=0;
	while(x)
	{
		res++;
		x/=10;
	}
	return res;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&p);
	DLL ans=n,maxx=0;
	ans%=p;
	f[ans]++;
	maxx=max(maxx,ans);
	for(int i=2;i<=m;i++)
	{
		ans=ans*(ll)pow(10,lenth(n))+n;
		ans%=p;
	    f[ans]++;
	    maxx=max(maxx,ans);
	    if(f[ans]==2)
	    break;
	}
	printf("%lld",maxx);
	return 0;
}