#include<bits/stdc++.h>
using namespace std;
map<string,string> mp1;
map<string,string> mp2;
vector<string> vec;
int T,n;
int main ()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		mp1.clear();
		mp2.clear();
		vec.clear();
		scanf("%d",&n);
		string u,v;
		for(int j=1;j<=n;j++)
		{
			cin>>u>>v;
			mp1[v]=u;
			mp2[u]=v;
			vec.push_back(u);
		}
		for(int it=0;it<vec.size();it++)
		{
		   if(mp1[vec[it]]!="")
		   continue;
		   u=vec[it];
		   break;
		}
		cout<<"Case #"<<i<<":";
		for(string j=u;j!="";j=mp2[j])
		{
			if(mp2[j]!="")
			cout<<" "<<j<<"-"<<mp2[j];
			else
			break;
		}
		cout<<endl;
	}
	return 0;
}