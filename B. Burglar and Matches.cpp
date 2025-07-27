#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,res;
pair<int,int> p[50];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].second>>p[i].first;
	}
	sort(p+1,p+1+m);
	for(int i=m;i>=1;i--)
	{
		if(n>=p[i].second)
		{
			res+=p[i].second*p[i].first;
			n-=p[i].second;
		}
		else
		{
			res+=n*p[i].first;
			break;
		}
	}
	cout<<res;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}