#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[100010],res;
struct node
{
	int pos,num;
}s[100010];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
void solve()
{
	res=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].num;
		s[i].pos=i;
		res+=s[i].num;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=n;i>=1;i--)
	{
		if(i==n)
		{
			dp[s[i].pos]=n;
		}
		else
		{
			if(res>=s[i+1].num) dp[s[i].pos]=dp[s[i+1].pos];
			else dp[s[i].pos]=i;
		}
		res-=s[i].num;
	}
	for(int i=1;i<=n;i++) cout<<dp[i]-1<<" ";
	cout<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}