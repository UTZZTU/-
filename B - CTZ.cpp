#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	int res=0;
	while(n)
	{
		if(n%2==1) break;
		else res++;
		n/=2;
	}
	cout<<res<<endl;
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