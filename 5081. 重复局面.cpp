#include <bits/stdc++.h>
using namespace std;
int n;
string u,v;
map<string,int> mp;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		u.clear();
		for(int j=1;j<=8;j++)
		{
			cin>>v;
			u+=v;
		}
		mp[u]++;
		cout<<mp[u]<<endl;
	}
	return 0;
}