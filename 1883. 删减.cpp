#include <bits/stdc++.h>
using namespace std;
string s,t,res;
int main ()
{
	getline(cin,s);
	getline(cin,t);
	int slen=s.size(),tlen=t.size();
	for(int i=0;i<slen;i++)
	{
		res+=s[i];
		if(res.size()>=tlen&&res.substr(res.size()-tlen,tlen)==t)
		{
			res.erase(res.begin()+res.size()-tlen,res.end());
		}
	}
	cout<<res;
	return 0;
}