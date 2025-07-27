#include <bits/stdc++.h>
using namespace std;
int y,w;
void solve()
{
	cin>>y>>w;
	int maxx=max(y,w);
	int a=6-maxx+1,b=6;
	int gcds=__gcd(a,b);
	a/=gcds,b/=gcds;
	cout<<a<<"/"<<b<<endl;
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