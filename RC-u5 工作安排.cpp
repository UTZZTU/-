#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int t,d,p;
}s[5010];
bool cmp(node x,node y)
{
	if(x.d-x.t!=y.d-y.t)
	return x.d-x.t<y.d-y.t;
	else
	{
		return x.d<y.d;
	}
}
ll n,t[5010],d[5010],p[5010],dp[5010],mm;
/*
1
5
100 101 1
100 101 1
100 9 8
1 100 5
18 18 2000

2000
*/
//struct 
void solve()
{
	mm=0;
	cin>>n;
	for(int i=0;i<=5000;i++) dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].t>>s[i].d>>s[i].p;
//		mm=max(mm,d[i]);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i].d;j-s[i].t>=0;j--)
		{
			
			dp[j]=max(dp[j],dp[j-s[i].t]+s[i].p);
//			for(int k=j+1;k<=mm;k++)
//			{
//				dp[k]=max(dp[k],dp[k-1]);
//			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			dp[i]=max(dp[i],dp[i-1]);
//		}
	}
//	for(int i=1;i<=100;i++)
//	{
//		cout<<i<<" "<<dp[i]<<endl;
//	}
	ll maxx=0;
	for(int i=0;i<=5000;i++)
	{
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
