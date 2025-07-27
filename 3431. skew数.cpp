#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string n;
ll num(string s)
{
	ll res=0,k=s.size();
	for(int i=0;i<s.size();i++)
	{
		res+=(ll)(s[i]-'0')*(ll)(pow(2,k)-1);
		k--;
	}
	return res;
}
int main ()
{
	while(cin>>n)
	{
		cout<<num(n)<<endl;
	}
	return 0;
}