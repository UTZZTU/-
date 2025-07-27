#include <bits/stdc++.h>
using namespace std;
int x,k;
void solve()
{
	cin>>x>>k;
	if(x%k!=0)
	{
		cout<<1<<endl;
		cout<<x<<endl;
	}
	else
	{
		cout<<2<<endl;
		cout<<x+1<<endl;
		cout<<-1<<endl;	
	}
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