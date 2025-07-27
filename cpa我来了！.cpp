#include <bits/stdc++.h>
using namespace std;
string u;
map<char,int> mp;
int judge;
int main ()
{
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		mp[u[i]]++;
		if(i>=2)
		{
			if((u[i-2]=='c'||u[i-2]=='C')&&(u[i-1]=='p'||u[i-1]=='P')&&(u[i]=='a'||u[i]=='A'))
			{
				judge=1;
			}
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<":"<<it->second<<endl;
	}
	if(judge) cout<<"^_^";
	else cout<<"T_T";
	return 0;
}