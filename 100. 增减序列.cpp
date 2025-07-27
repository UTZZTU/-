#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],res,zs,fs;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>1)
		{
			res+=a[i]-a[i-1];
			if(a[i]-a[i-1]>=0)
			zs+=(a[i]-a[i-1]);
			else
			fs+=abs(a[i]-a[i-1]);
		}
	}
	cout<<max(zs,fs)<<endl<<abs(res)+1;
	return 0;
}