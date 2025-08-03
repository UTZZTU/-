#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void solve()
{
	cin>>s;
	if(s[0]!='1'||s.size()<3) cout<<"NO"<<endl;
	else
	{
		int pos=1;
		while(pos<s.size()&&s[pos]=='0') pos++;
		if(pos<=1||pos>=3) cout<<"NO"<<endl;
		else
		{
			if(s[pos]=='1'&&s.size()>=4||s[pos]>='2') cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}