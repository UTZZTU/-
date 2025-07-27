#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	char c1=s[0];
	int c2=s[1]-'0';
	for(int i=1;i<=8;i++)
	{
		if(i!=c2)
		{
			cout<<c1<<i<<endl;
		}
	}
	for(int i=0;i<8;i++)
	{
		if(('a'+i)!=c1)
		{
			cout<<char('a'+i)<<c2<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}