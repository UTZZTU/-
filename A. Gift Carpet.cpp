#include <bits/stdc++.h>
using namespace std;
int t,n,m,flag;
string s[50];
void dfs(int level,vector<char> vec)
{
	if(flag) return;
	if(vec.size()==4)
	{
		flag=1;
		return;
	}
	if(level>=m) return;
	for(int j=1;j<=n;j++)
	{
		if(vec.size()==0&&s[j][level]=='v')
		{
			vec.push_back(s[j][level]);
			dfs(level+1,vec);
			vec.pop_back();
			break;
		}
		if(vec.size()==1&&s[j][level]=='i')
		{
			vec.push_back(s[j][level]);
			dfs(level+1,vec);
			vec.pop_back();
			break;
		}
		if(vec.size()==2&&s[j][level]=='k')
		{
			vec.push_back(s[j][level]);
			dfs(level+1,vec);
			vec.pop_back();
			break;
		}
		if(vec.size()==3&&s[j][level]=='a')
		{
			vec.push_back(s[j][level]);
			dfs(level+1,vec);
			vec.pop_back();
			break;
		}
	}
	dfs(level+1,vec);
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		flag=0;
		vector<char> vec;
		dfs(0,vec);
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}