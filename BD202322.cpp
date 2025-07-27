#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a,m,ans0,ans1,ne0,ne1;
int main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&m);
		if(a>k)
		{
			ans0=ans1=min(ans0+k,ans1)+(a-k)*m;
		}
		else
		{
			ne0=min(ans0+(m+1)/2*a,ans1+m/2*a);
			ne1=min(ans0+(m+2)/2*a,ans1+(m+1)/2*a);
			ans0=ne0,ans1=ne1;
		}
	}
	printf("%lld\n",min(ans0,ans1));
	return 0;
}