#include <bits/stdc++.h>
using namespace std;
int n,m,res,cnt;
unordered_map<string,string> mp;
string u,v;
vector<string> vec;
vector<string> vt;
void dfs(int level,vector<string> tt,string r)
{
	if(level==cnt)
	{
		if(r.size()) tt.push_back(r);
		int judge=0;
		for(int i=0;i<tt.size();i++)
		{
			if(!(mp[tt[i]]=="A"||mp[tt[i]]=="B"||mp[tt[i]]=="C"||mp[tt[i]]=="D"))
			{
				judge=1;
				break;
			}
		}
		if(!judge)
		{
			res++;
			vt=tt;
		}
		return;
	}
	tt.push_back(r);
	dfs(level+1,tt,vec[level]);
	tt.pop_back();
	dfs(level+1,tt,r+vec[level]);
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		mp[u]=v;
	}
	while(m--)
	{
		vec.clear();
		vt.clear();
		vector<string> o;
		string r;
		res=0;
		v.clear();
		cin>>u;
		if(mp[u]=="A"||mp[u]=="B"||mp[u]=="C"||mp[u]=="D")
		{
			cout<<mp[u]<<endl;
			continue;
		}
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='A'&&u[i]<='Z')
			{
				if(v.size())
				vec.push_back(v);
				v.clear();
				v+=u[i];
			}
			else
			{
				v+=u[i];
			}
		}
		if(v.size())
		vec.push_back(v);
		r=vec[0];
		cnt=vec.size();
		dfs(1,o,r);
		if(res==1)
		{
			v.clear();
			for(int i=0;i<vt.size();i++)
			{
				v+=mp[vt[i]];
			}
			cout<<v<<endl;
		}
		else
		{
			printf("D\n");
		}
	}
	return 0;
}