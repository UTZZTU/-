#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int n,c,dp[1000010],k;
deque<pair<int,int>> q;
signed main ()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		cin>>k;
		while(q.size()&&(i-q.front().se)>=c) q.pop_front();
		while(q.size()&&q.back().fi>=k) q.pop_back();
		q.push_back({k,i});
		if(i>=c)
		{
			dp[i]=max(dp[i],dp[i-c]+q.front().fi);
		}
	}
	cout<<dp[n];
	return 0;
}