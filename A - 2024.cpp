#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size()-1;i++) cout<<s[i];
	cout<<"4"<<endl;
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