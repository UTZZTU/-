#include <bits/stdc++.h>
using namespace std;
string s;
int f[30],res;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<26;j++)
		{
			int tt=abs((s[i]-'a')-j);
			int minn=min(tt,26-tt);
			f[j]+=minn;
		}
	}
	res=f[0];
	for(int i=0;i<26;i++)
	{
		res=min(res,f[i]);
	}
	cout<<res;
	return 0;
}