#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,mb;
int get_num(string s)
{
	int t=0;
	for(int i=0;i<s.size();i++)
	{
		if(i==0) t+=2;
		else if(s[i]==s[i-1]) t+=1;
		else t+=2;
	}
	return t;
}
void solve()
{
	cin>>s;
	int maxx=0;
	mb.clear();
	string t;
	for(int i=0;i<26;i++)
	{
		t=s;
		reverse(t.begin(),t.end());
		t+=('a'+i);
		reverse(t.begin(),t.end());
		int ans=get_num(t);
		if(ans>maxx)
		{
			maxx=ans;
			mb=t;
		}
	}
	for(int k=0;k<26;k++)
	{
		for(int i=1;i<=s.size();i++)
		{
			string ss;
			for(int j=0;j<i;j++)
			{
				ss+=s[j];
			}
			ss+=('a'+k);
			for(int j=i;j<s.size();j++)
			{
				ss+=s[j];
			}
			int ans=get_num(ss);
			if(ans>maxx)
			{
				maxx=ans;
				mb=ss;
			}
		}
	}
	cout<<mb<<endl;
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