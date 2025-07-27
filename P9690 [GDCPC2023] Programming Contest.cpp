#include <bits/stdc++.h>
using namespace std;
int t,u,n,s,v,res;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>u;
		cin>>n;
		map<int,bool> mp;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			mp[s]=true;
		}
		cin>>v;
		res=0;
		for(int i=u;i<=v;i++)
		{
			if(!mp[i]) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}