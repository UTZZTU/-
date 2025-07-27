#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res1,res2;
string s;
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(i&1)
		{
			if(s[i]!='1') res1+=(i+1);
			if(s[i]!='0') res2+=(i+1);
		}
		else
		{
			if(s[i]!='0') res1+=(i+1);
			if(s[i]!='1') res2+=(i+1);
		}
	}
	printf("%lld",min(res1,res2));
	return 0;
}