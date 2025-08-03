#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void solve()
{
	cin>>n;
	if(n%4==0)
	{
		cout<<n/4<<endl;
	}
	else cout<<n/4+1<<endl;
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