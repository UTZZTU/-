#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[100010],res,pos;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	sort(f+1,f+1+n);
	for(int i=n;i>=1;i--)
	{
		if(f[i]*(n+1-i)>=res)
		{
			pos=f[i];
			res=f[i]*(n+1-i);
		}
	}
	printf("%lld %lld",res,pos);
	return 0;
}