#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
string s;
ll num[500010],res;
void solve()
{
	res=0;
	cin>>s;
	ll cnt=210000;
	ll pp=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') pp++;
	}
	for(int i=210000-pp-100;i<=210000+(s.size()-pp)+100;i++)
	{
		num[i]=0;
	}
	num[cnt]=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') cnt--;
		else cnt++;
//		cout<<num[cnt]<<" "<<s.size()-i<<endl;
		res=(res+(num[cnt])%MOD*((ll)s.size()-i)%MOD)%MOD;
		num[cnt]=(num[cnt]+i+2)%MOD;
//		cout<<res<<endl;
	}
	cout<<res<<endl;
}
/*
1 23 45
2 1
3 2
4 2
5 1
*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}