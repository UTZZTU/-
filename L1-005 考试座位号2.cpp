#include <bits/stdc++.h>
using namespace std;
map<string,pair<string,string>>mp;
string a,b,c;
int n,m;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		mp[b]={a,c};
	}
	cin>>m;
	getchar();
	while(m--)
	{
		cin>>b;
		cout<<mp[b].first<<" "<<mp[b].second<<endl;
	}
	return 0;
}