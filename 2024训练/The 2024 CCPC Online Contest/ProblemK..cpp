#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,k;
ll lowbit(ll x)
{
	return x&-x;
}
void solve()
{
	cin>>n>>k;
	if(lowbit(n)<=k) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}