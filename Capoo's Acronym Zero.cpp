#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> >mp;
int n,q;
string u;
int main ()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		string v;
		for(int j=0;j<u.size();j++)
		{
			if(u[j]>='A'&&u[j]<='Z')
			{
				v+=u[j];
			}
		}
		mp[v].push_back(u);
	}
	while(q--)
	{
		cin>>u;
		vector<string> vec=mp[u];
		cout<<vec.size()<<endl;
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i]<<endl;
		}
	}
	return 0;
}