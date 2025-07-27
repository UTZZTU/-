#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[300010],b[300010],res1,res2;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res1=res2=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),res1+=a[i];
		for(int j=1;j<=n;j++) scanf("%lld",&b[j]),res2+=b[j];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		cout<<min(res1+n*(b[1]),res2+n*(a[1]))<<endl;
	}
	return 0;
}