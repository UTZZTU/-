#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
string s;
void solve()
{
	cin>>n;
	cin>>s;
	stack<char> st;
	for(int i=0;i<n;i++)
	{
		if(st.empty()) st.push(s[i]);
		else
		{
			if(s[i]=='c'&&st.top()=='f') st.pop();
			else if(s[i]=='b'&&st.top()=='t') st.pop();
			else st.push(s[i]);
		}
	}
	cout<<st.size()<<endl;
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