#include <bits/stdc++.h>
using namespace std;
int n,q,d,last;
void solve()
{
	cin>>n>>q;
	last=n-1;
	for(int i=2;i<=n;i++) cout<<i-1<<" "<<i<<endl;
	while(q--)
	{
		cin>>d;
		if(d==last) cout<<-1<<" "<<-1<<" "<<-1<<endl;
		else
		cout<<n<<" "<<last<<" "<<d<<endl;
		last=d;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}