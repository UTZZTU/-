#include <bits/stdc++.h>
using namespace std;
string s;
int res;
void solve()
{
	cin>>s;
	for(auto c:s)
	{
		if(c=='o') res++;
	}
	cout<<res;
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