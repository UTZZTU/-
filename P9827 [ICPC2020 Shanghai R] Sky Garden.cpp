#include <bits/stdc++.h>
using namespace std;
#define int long long
const double pi = acos(-1);
int n,m;
double res;
double calc(int x)
{
	double sum=0;
	for(int i=1;i<m;i++)
	{
		sum+=min(2.0*x,pi*i/m*x);
	}
	sum*=2;
	sum+=2.0*x;
	return sum;
}
signed main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j) res+=calc(i)*m;
			else res+=(calc(j)+2*m*(i-j))*2*m;
		}
	}
	if(m>1) res+=n*(n+1)*m;
	printf("%.10f",res);
	return 0;
}