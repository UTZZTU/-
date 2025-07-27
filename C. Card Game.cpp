#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],res;
void solve()
{
	cin>>n;
	res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=3&&a[i]>0) res+=a[i];
	}
	if(n==1)
	{
		cout<<max((int)0,a[1])<<endl;
		return;
	}
	cout<<max(max(res+a[1],res+a[1]+a[2]),res)<<endl;
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