#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll res=1;
string s;
int main ()
{
	cin>>s;
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(i==j)
		{
			if(s[i]=='?') res=res*(ll)26%mod;
		}
		else
		{
			if(s[i]=='?'&&s[j]=='?') res=res*(ll)26%mod;
			else if(s[i]=='?'||s[j]=='?') res=res%mod;
			else if(s[i]!=s[j]) res=0;
		}
	}
	cout<<res;
	return 0;
}