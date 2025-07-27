#include <bits/stdc++.h>
using namespace std;
int w;
void solve()
{
	cin>>w;
	if(w&1) cout<<"NO"<<endl;
	else if(w<=2) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}