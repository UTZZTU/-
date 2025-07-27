#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[100],fs[100],sum;
int main ()
{
	string s;
	cin>>s;
	for(int i=0;i<26;i++) cin>>fs[i];
	for(int i=0;i<s.size();i++)
	{
		c[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		sum+=c[i]*fs[i];
	}
	for(int i=0;i<26;i++)
	{
		if(i!=0) cout<<" ";
		cout<<c[i];
	}
	cout<<endl;
	cout<<sum;
	return 0;
}
