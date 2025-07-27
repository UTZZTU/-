#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
typedef pair<int,int> PII;
struct node
{
	int k,p;
}s[100010];
bool cmp(node x,node y)
{
	return x.p<y.p;
}
int n;
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&s[i].k,&s[i].p);
	}
	sort(s+1,s+1+n,cmp);
	if(n-1>=1&&s[n].p==s[n-1].p+1)
	{
		int k=(s[n].k*s[n].p)%MOD;
		k=(k+s[n-1].k)%MOD;
		int p=s[n-1].p;
		while(p>0)
		{
			k=(k*p)%MOD;
			p--;
		}
		printf("%lld\n",k);
	}
	else
	{
		int k=(s[n].k)%MOD;
		int p=s[n].p;
		while(p>0)
		{
			k=(k*p)%MOD;
			p--;
		}
		printf("%lld\n",k);
	}
	return 0;
}