#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	string t;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]!='0')
		{
			for(int j=0;j<i;j++)
			{
				t+=s[j];
			}
			break;
		}
	}
	cout<<t<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}