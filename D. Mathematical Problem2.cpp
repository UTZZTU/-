#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string get_str1(int x)
{
	string u="1";
	for(int i=1;i<=x;i++) u+='0';
	u+='6';
	for(int i=1;i<=x;i++) u+='0';
	u+='9';
	return u;
}
string get_str2(int x)
{
	string u="9";
	for(int i=1;i<=x;i++) u+='0';
	u+='6';
	for(int i=1;i<=x;i++) u+='0';
	u+='1';
	return u;
}
void solve()
{
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
	}
	else if(n==3)
	{
		cout<<169<<endl;
		cout<<196<<endl;
		cout<<961<<endl;
	}
	else
	{
		vector<string> vec;
		for(int i=0;i<=(n-3)/2;i++)
		{
			string s=get_str1(i);
			while(s.size()<n) s+='0';
			vec.push_back(s);
		}
		for(int i=0;i<=(n-3)/2;i++)
		{
			string s=get_str2(i);
			while(s.size()<n) s+='0';
			vec.push_back(s);
		}
		string u="196";
		while(u.size()<n) u+='0';
		vec.push_back(u);
		string v="61009";
		while(v.size()<n) v+='0';
		vec.push_back(v);
		for(int i=0;i<n;i++)
		{
			cout<<vec[i]<<endl;
		}
	}
	
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
/*
10609
16900
19600
61009
90601
96100

1006009
1060900
1690000
1960000
6100900
9006001
9060100
9610000
*/