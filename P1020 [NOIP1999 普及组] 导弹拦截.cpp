#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100010],cnt,k,dp[100010];
bool check(int x)
{
	multiset<int> s;
	for(int i=1;i<=cnt;i++)
	{
		auto it=s.lower_bound(f[i]);
		if(it==s.end())
		{
			s.insert(f[i]);
			if(s.size()>x) return false;
		}
		else
		{
			s.erase(it);
			s.insert(f[i]);
		}
	}
	return true;
}
int main ()
{
	while(~scanf("%d",&k))
	{
		f[++cnt]=k;
	}
	dp[1]=f[1];
	int last=1;
	for(int i=2;i<=cnt;i++)
	{
		if(f[i]<=dp[last]) dp[++last]=f[i];
		else
		{
			*upper_bound(dp+1,dp+1+last,f[i],greater<int>())=f[i];
		}
	}
	cout<<last<<endl;
	int l=1,r=cnt;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r;
	return 0;
}