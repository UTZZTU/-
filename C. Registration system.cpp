#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n;
string s;
void solve()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(mp[s]==0) cout<<"OK"<<endl;
		else
		{
			string t=to_string(mp[s]);
//			s+=t;
			t=s+t;
			cout<<t<<endl;
		}
		mp[s]++;
	}
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