#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll k,w[30],maxx,res;
int main ()
{
	cin>>s;
	cin>>k;
	for(int i=0;i<26;i++)
	{
		cin>>w[i];
		maxx=max(maxx,w[i]);
	}
	for(int i=0;i<s.size();i++)
	{
		res+=w[s[i]-'a']*(i+1);
	}
	for(int i=s.size()+1;i<=s.size()+k;i++)
	{
		res+=maxx*i;
	}
	cout<<res;
	return 0;
}