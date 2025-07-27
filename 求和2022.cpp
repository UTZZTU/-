#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll f[N],n,res,k;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		k+=f[i];
	}
	for(int i=1;i<=n;i++)
	{
		res+=(k-f[i])*f[i];
	}
	cout<<res/2<<endl;
	return 0;
}