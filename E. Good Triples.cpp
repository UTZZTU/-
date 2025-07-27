#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
void solve()
{
	res=1;
	cin>>n;
	while(n)
	{
		int num=n%10;
		res*=(num+1)*(num+2)/2;
		n/=10;
	}
	cout<<res<<endl;
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