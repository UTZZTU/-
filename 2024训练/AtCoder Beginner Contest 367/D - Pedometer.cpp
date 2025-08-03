#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],b[400010],res,tt[400010],sum;
map<ll,ll> mp;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=n+1;i<=2*n;i++)
	{
		b[i]=a[i-n];
	}
	mp[res]++;
	tt[1]=res;
	for(int i=1;i<n;i++)
	{
		res+=b[i];
		res%=m;
		mp[res]++;
		tt[i+1]=res;
	}
	for(int i=n;i<2*n;i++)
	{
		int j=i-n+1;
		sum+=mp[tt[j]]-1;
		res+=b[i];
		res%=m;
		mp[res]++;
		mp[tt[j]]--;
	}
	cout<<sum<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}