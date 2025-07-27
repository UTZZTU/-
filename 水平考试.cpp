#include <bits/stdc++.h>
using namespace std;
string s,f;
bool judge()
{
	for(int i=0;i<s.size();i++)
	{
		int pos=f.find(s[i]);
		if(pos==-1) return true;	
	}
	return false;
}
void solve()
{
	cin>>s>>f;
	if(judge())
	{
		cout<<0<<endl;
		return;
	}
	cout<<10<<endl;
}
int main ()
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
	return 0;
}