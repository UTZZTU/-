#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==')'&&st.size()&&st.top()=='(') st.pop();
		else st.push(s[i]);
	}
	cout<<(int)s.size()-(int)st.size()<<endl;
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