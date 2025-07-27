#include <bits/stdc++.h>
using namespace std;
string s;
int pos;
void solve()
{
	pos=-1;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!='0')
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		cout<<-1<<endl;
		return;
	}
	int a=0,b=0;
	for(int i=0;i<pos;i++)
	{
		a=a*10+(s[i]-'0');
	}
	for(int i=pos;i<s.size();i++)
	{
		b=b*10+(s[i]-'0');
	}
	if(b>a) cout<<a<<" "<<b<<endl;
	else cout<<-1<<endl;
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
}