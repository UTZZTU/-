#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x;
void solve()
{
	cin>>a>>b>>x;
	if(a*3ll<=b)
	{
		cout<<x*a;
	}
	else 
	{
		cout<<(x/3ll)*b+min((x%3)*a,b);
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