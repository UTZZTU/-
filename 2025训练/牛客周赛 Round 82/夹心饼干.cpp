#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s;
void solve()
{
	cin>>s;
	if(s[0]==s[2]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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