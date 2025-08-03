#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void solve()
{
	set<char> st;
	cin>>s;
	for(auto c:s)
	{
		st.insert(c);
	}
	if(st.size()==1) cout<<0<<endl;
	else if(st.size()==2) cout<<1<<endl;
	else cout<<2<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}