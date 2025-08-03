#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll t,d,p,cnt;
}s[5010];
bool cmp(node x,node y)
{
	return x.d<y.d;
}
ll n,dp[5010],maxx;
void solve()
{
	maxx=0;
	memset(dp,0,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].t>>s[i].d>>s[i].p;
		s[i].cnt=s[i].d-s[i].t;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i].cnt;j>=0;j--)
		{
			dp[j+s[i].t]=max(dp[j+s[i].t],dp[j]+s[i].p);
			maxx=max(maxx,dp[j+s[i].t]);
		}
	}
	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}