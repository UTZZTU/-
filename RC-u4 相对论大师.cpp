#include <bits/stdc++.h>
using namespace std;
map<string,vector<pair<string,string>>> mp;
vector<string> vec;
string u,v,a,b,s[1010],uu,vv,aa,bb;
int n,jj;
void dfs(string str,vector<string> vc,map<string,bool> m)
{
	vc.push_back(str);
	if(vc.size()>=3&&vc[0]==vc[vc.size()-1])
	{
		if(vc[1][0]!=vc[vc.size()-2][1])
		{
			if(vec.size()==0||vc.size()<vec.size())
			vec=vc;
		}
		return;
	}
	if(m[str]==true) return;
	m[str]=true;
	vector<pair<string,string>> vp=mp[str];
	for(int i=0;i<vp.size();i++)
	{
		vc.push_back(vp[i].second);
		dfs(vp[i].first,vc,m);
		vc.pop_back();
	}
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u>>a>>v>>b;
		if(u==v&&a!=b) uu=u,vv=v,aa=a,bb=b,jj=1;
		mp[u].push_back({v,a+b});
		s[i]=u;
	}
	if(jj)
	{
		cout<<uu<<" "<<aa<<" "<<vv<<" "<<bb<<" = "<<uu<<" "<<aa<<" "<<vv<<" "<<bb<<endl;
		return 0;
	}
	vector<string> vc;map<string,bool> m;
	for(int i=1;i<=n;i++)
	{
		dfs(s[i],vc,m);
	}
	for(int i=0;i<vec.size();i+=2)
	{
		if(i+2>=vec.size()) break;
		cout<<vec[i]<<" "<<vec[i+1][0]<<" "<<vec[i+2]<<" "<<vec[i+1][1]<<" ";
	}
	cout<<"= ";
	cout<<vec[0]<<" "<<vec[1][0]<<" "<<vec[0]<<" "<<('1'-vec[1][0]);
	return 0;
}