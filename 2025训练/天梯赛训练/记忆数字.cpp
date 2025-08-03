#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s;
int cnt;
void solve()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=' '&&s[i]!=','&&s[i]!='.'&&s[i]!='?'&&s[i]!='!') cnt++;
		else
		{
            if(cnt>0)
			cout<<cnt%10;
			cnt=0;
		}
	}
	if(cnt>0) cout<<cnt%10;
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