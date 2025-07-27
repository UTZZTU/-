#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],res;
int lowbit(int x)
{
	return x & -x;
}
bool judge()
{
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		a[i]-=res;
		int k=abs(a[i]);
		int low=lowbit(k);
		k+=low;
		if(k!=lowbit(k)) return false;
		if(a[i]>0)
		{
			mp[low]++;
			mp[k]--;
		}
		if(a[i]<0)
		{
			mp[k]++;
			mp[low]--;
		}
//		cout<<k<<endl;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
//		cout<<it->second<<endl;
		if(it->second!=0) return false;
	}
	return true;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res+=a[i];
		}
		if(res%n!=0) puts("No");
		else
		{
			res/=n;
			if(judge())
			{
				puts("Yes");
			}
			else
			puts("No");
		}
	}
	return 0;
}