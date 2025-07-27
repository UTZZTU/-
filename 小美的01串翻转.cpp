#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,tt1,tt2;
string s;
int main ()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		tt1=tt2=0;
		for(int j=i;j<s.size();j++)
		{
			if((j-i)%2==0)
			{
				if(s[j]=='0') tt1++;
				else tt2++;
			}
			else
			{
				if(s[j]=='0') tt2++;
				else tt1++;
			}
			res+=min(tt1,tt2);
		}
	}
	cout<<res;
	return 0;
}