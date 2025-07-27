#include <bits/stdc++.h>
using namespace std;
int ans,n;
string u,v;
int main ()
{
	while(cin>>n)
	{
		if(!n)
		break;
		getchar();
		map<string,int> mp;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>u>>v;
			mp[v]=-1;
			if(!mp.count(u))
			mp[u]=1;
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->second==1)
			ans++;
		}
		if(ans==1)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}