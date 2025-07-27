#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll f[100010],t,n;
int main ()
{
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=100000;i++)
	f[i]=(f[i-1]+f[i-2])%MOD;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}