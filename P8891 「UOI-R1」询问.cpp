#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,y,f[1000010];
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		f[x]-=y;
	}
	for(int i=1;i<=n;i++)
	printf("%lld ",f[i]);
	return 0;
}