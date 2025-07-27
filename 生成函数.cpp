#include <bits/stdc++.h>
using namespace std;
int a,b,c,m;
void solve()
{
	cin>>a>>b>>c>>m;
	int gcds=__gcd(__gcd(a,b),c);
	if(m%gcds==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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