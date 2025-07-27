#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010],m[100010],res,tt;
//bool check(int x)
//{
//	
//}
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&m[i]);
//		res+=a[i]*m[i];
	}
//	int l=1,r=res;
//	while(l<r)
//	{
//		int mid=l+r>>1;
//		if(check(mid))
//		{
//			r=mid;
//		}
//		else
//		l=mid+1;
//	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k)
		{
			tt+=(a[i]-k)*m[i];
		}
		else
		{
			tt+=a[i];
			m[i]-=1;
			tt+=(m[i]/2)*a[i];
		}
	}
	printf("%lld",tt);
	return 0;
}