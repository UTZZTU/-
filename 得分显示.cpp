#include <bits/stdc++.h>
using namespace std;
#define int long long
const double eps = 1e-6;
int n,f[1000010];
bool check(double x)
{
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=x;
		int t=(int)sum;
		if(t>f[i]) return false;
	}
	return true;
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	double l=0,r=1e9+1;
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.6f",l);
	return 0;
}