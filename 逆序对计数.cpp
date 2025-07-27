#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[6010][6010],n,q,l,r,ans,a[6010];
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				ans++;
				f[i][j]=f[i+1][j]-f[i+1][j-1]+f[i][j-1]+1;
			}
			else
			f[i][j]=f[i+1][j]-f[i+1][j-1]+f[i][j-1];
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%d %d",&l,&r);
		ll cz=(r-l+1)*(r-l)/2;
		cz=2*f[l][r]-cz;
		cout<<ans-cz<<endl;
	}
	return 0;
}