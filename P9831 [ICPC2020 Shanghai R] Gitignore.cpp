#include <bits/stdc++.h>
using namespace std;
map<string,bool> cnt,vis;
int t,n,m,res;
string s[1010],u;
int main ()
{
	cin>>t;
	while(t--)
	{
		cnt.clear();
		res=0;
		vis.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		for(int i=1;i<=m;i++)
		{
			string v="";
			cin>>u;
			for(int j=0;j<u.size();j++)
			{
				v+=u[j];
				if(u[j]=='/')
				{
					cnt[v]=true;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			string v="";
			int flag=1;
			for(int j=0;j<s[i].size();j++)
			{
				v+=s[i][j];
				if(s[i][j]=='/')
				{
					if(cnt[v])
					{
						flag=1;
					}
					else
					{
						if(vis[v]) flag=0;
						vis[v]=true;
						break;
					}
				}
			}
			res+=flag;
		}
		cout<<res<<endl;
	}
	return 0;
}