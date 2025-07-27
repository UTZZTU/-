#include <bits/stdc++.h>
using namespace std;
string s,u;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{
			u+='0';
		}
		else if(s[i]=='-'&&s[i+1]=='.')
		{
			i++;
			u+='1';
		}
		else
		{
			i++;
			u+='2';
		}
	}
	cout<<u<<endl;
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