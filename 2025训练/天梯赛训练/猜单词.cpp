#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s[10];
int a[10],b[10];
vector<string> vec;
bool check(string p)
{
//	cout<<p<<endl;
	for(int i=1;i<=5;i++)
	{
		int x=0,y=0;
		for(int j=0;j<3;j++)
		{
			if(p.find(s[i][j])!=-1) x++;
			if(p[j]==s[i][j]) y++;
		}
		if(x!=a[i]||y!=b[i]) return false;
	}
	return true;
}
void solve()
{
	for(int i=1;i<=5;i++)
	{
		cin>>s[i]>>a[i]>>b[i];
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				string u="";
				u+=(char)('A'+i);
				u+=(char)('A'+j);
				u+=(char)('A'+k);
				if(check(u)) vec.push_back(u);
			}
		}
	}
	cout<<vec.size()<<endl;
	for(auto c:vec)
	{
		cout<<c<<endl;
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