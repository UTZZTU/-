#include <bits/stdc++.h>
using namespace std;
int n,f[1000010],k,res;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int gcd1=__gcd(f[i]*f[j],k);
			int gcd2=__gcd(f[i],k);
			cout<<gcd1/gcd2<<endl;
			res+=gcd1/gcd2;
		}
	}
	cout<<res;
	return 0;
}