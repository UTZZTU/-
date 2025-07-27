#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll t,n,a[200010],x,flag;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		x=0;
		flag=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(!flag)
			{
				x+=a[i];
				if(x>1) flag=1;
			}
			else
			{
				if(a[i]==0||a[i]==1) x+=a[i];
				else x*=a[i];
			}
			x%=MOD;
		}
		printf("%lld\n",x);
	}
	return 0;
}