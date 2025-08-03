#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
void solve()
{
	cin>>x;
	cout<<x/10+x%10<<endl;
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