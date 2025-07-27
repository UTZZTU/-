#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
	cin>>n>>m;
	if(n%m==0)
	{
		cout<<0<<endl;
		return;
	}
	int cnt=0,pp=0;
	n%=m;
	while(pp<=50)
	{
		pp++;
		cnt+=n;
		n=(n*2)%m;
		if(n==0) break;
	}
	if(n%m==0) cout<<cnt<<endl;
	else cout<<-1<<endl;
}
signed main ()
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