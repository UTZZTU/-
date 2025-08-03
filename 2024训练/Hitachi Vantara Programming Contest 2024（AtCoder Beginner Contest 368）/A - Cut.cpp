#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k,f[1010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=n-k+1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	for(int i=1;i<n-k+1;i++)
	{
		cout<<f[i]<<" ";
	}
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