#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
pair<int,int> p[200010];
bool check(int x)
{
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		l-=x;
		r+=x;
		l=max(l,(int)0);
		if(p[i].first>r||p[i].second<l) return false;
		l=max(l,p[i].first);
		r=min(r,p[i].second);
//		cout<<x<<" "<<l<<" "<<r<<endl;
	}
	return true;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	int l=0,r=1e9+10;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}