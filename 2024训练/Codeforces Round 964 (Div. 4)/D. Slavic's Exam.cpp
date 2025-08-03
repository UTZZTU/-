#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
void solve()
{
	cin>>s>>t;
	int cnt=0;
	string v;
	for(auto c:s)
	{
		if(c=='?')
		{
			if(cnt>=t.size())
			{
				v+='a';
			}
			else
			{
				v+=t[cnt];
				cnt++;
			}
		}
		else
		{
			if(cnt>=t.size())
			{
				v+=c;
			}
			else
			{
				v+=c;
				if(t[cnt]==c) cnt++;
			}
		}
	}
	if(cnt>=t.size()) 
	{
		cout<<"YES"<<endl;
		cout<<v<<endl;
	}
	else cout<<"NO"<<endl;
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