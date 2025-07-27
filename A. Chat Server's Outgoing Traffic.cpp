#include <bits/stdc++.h>
using namespace std;
string s;
int cnt,res;
void solve()
{
	while(getline(cin,s))
	{
		int pos=s.find(':');
		if(pos==-1)
		{
			if(s[0]=='-') cnt--;
			else cnt++;
		}
		else
		{
			res+=(s.size()-pos-1)*cnt;
		}
	}
	cout<<res<<endl;
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