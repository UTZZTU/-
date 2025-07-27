#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n&1)
	{
		cout<<0<<endl;
		return;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res=res^a[i];
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}