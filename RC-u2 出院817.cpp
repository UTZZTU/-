#include <bits/stdc++.h>
using namespace std;
map<string,string> mp1,mp2;
int n,m;
string u,v,s[110];
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>v;
		u=s[i];
		mp1[u]=v;
		mp2[u]=v;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			string t=s[i]+s[j];
			if(mp1.count(t))
			{
				mp1[t]="D";
			}
			else
			{
				mp1[t]=mp1[s[i]]+mp1[s[j]];
			}
		}
	}
	while(m--)
	{
		cin>>u;
		if(mp2.count(u)) cout<<mp2[u]<<endl;
		else if(mp1.count(u)) cout<<mp1[u]<<endl;
		else cout<<"D"<<endl;
	}
	return 0;
}