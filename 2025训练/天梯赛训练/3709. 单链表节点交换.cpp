#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,f[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=2;i<=n;i+=2)
	{
		swap(f[i],f[i-1]);
	}
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