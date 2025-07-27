#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},n,m,res;
map<pair<int,int>, bool> mp;
vector<string> vec;
string u;
void dfs(int x,int y)
{
	mp[{x,y}]=true;
	for(int i=0;i<4;i++)
	{
		int xx=dx[i]+x,yy=dy[i]+y;
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&vec[xx][yy]=='1'&&!mp[{xx,yy}])
		{
			dfs(xx,yy);
		}
	}
}
int main ()
{
	while(cin>>u)
	{
		vec.push_back(u);
	}
	n=vec.size(),m=vec[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='1'&&!mp[{i,j}])
			{
				res++;
				dfs(i,j);
			}
		}
	}
	if(res==5) cout<<"Y";
	else if(res==7) cout<<"S";
	else cout<<"E";
	return 0;
}