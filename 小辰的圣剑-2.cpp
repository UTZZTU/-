#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,a[5010],b[5010],maxx;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(b[i]-b[i-x]<=u&&a[i]-a[i-x]<=m) return true;
	}
	return false;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&u);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
//		cout<<a[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int res1=a[i],res2=b[i];
		for(int j=i+1;j<=n;j++)
		{
			if(res1+a[j]<=m&&res2+b[j]<=u)
			{
				res1+=a[j];
				res2+=b[j];
				maxx=max(maxx,j-i+1);
			}
			else
			{
				maxx=max(maxx,j-i);
				break;
			}
		}
	}
	printf("%lld",maxx);
	return 0;
}