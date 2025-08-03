#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[500010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	for(int i=3;i<=n;i++)
	{
		if(f[i]*f[i-1]<=f[i-1]*f[i-2])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<f[i]<<" ";
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