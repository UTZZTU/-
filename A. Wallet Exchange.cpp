#include <bits/stdc++.h>
using namespace std;
int a,b;
void solve()
{
	cin>>a>>b;
	if((a+b)&1) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}