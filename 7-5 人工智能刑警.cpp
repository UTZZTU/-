#include <bits/stdc++.h>
using namespace std;
map<vector<int>,string> mp;
int main ()
{
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		vector<int> p;
		for(int j=1;j<=m;j++)
		{
			int k;
			cin>>k;
			p.push_back(k);
		}
		    string u;
			cin>>u;
			mp[p]=u;
	}
	while(cin>>a)
	{
		int pd=0;
		vector<int> p;
		p.push_back(a);
		for(int i=1,k;i<m;i++)
		{
			cin>>k;
			p.push_back(k);
		}
		if(a==0)
		break;
		else
		{
			if(mp.count(p)==0)
			cout<<"Pass"<<endl;
			else
			cout<<mp[p]<<endl;
		}
	}
	return 0;
}