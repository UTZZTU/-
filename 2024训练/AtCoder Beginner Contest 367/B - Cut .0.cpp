#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void solve()
{
	cin>>s;
	int pos=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='0') pos++;
		else break;
	}
	if(pos==3)
	{
		for(int i=0;i<=s.size()-5;i++)
		{
			cout<<s[i];
		}
	}
	else
	{
		for(int i=0;i<=s.size()-1-pos;i++)
		{
			cout<<s[i];
		}
	}
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