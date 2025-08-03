#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s,t,u;
void solve()
{
	map<char,bool> mp;
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]]=true;
	}
	for(int i=0;i<t.size();i++)
	{
		if(t[i]==s[i])
		{
			u+="g";
		}
		else if(mp[t[i]]) u+="y";
		else u+="r";
	}
	cout<<u<<endl;
	if(u=="gggggggg") cout<<"congratulations"<<endl;
	else cout<<"defeat"<<endl;
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