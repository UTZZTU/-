#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010];
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		map<int,bool> mp1,mp2;
		int flag=0,res=0;
		mp1[0]=true;
		mp2[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(i&1) res+=a[i];
			else res-=a[i];
			if(mp1[res])
			{
				flag=1;
				break;
			}
			else mp1[res]=true;
		}
		res=0;
		for(int i=n;i>=1;i--)
		{
			if((n-i+1)&1) res+=a[i];
			else res-=a[i];
			if(mp2[res])
			{
				flag=1;
				break;
			}
			else mp2[res]=true;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}