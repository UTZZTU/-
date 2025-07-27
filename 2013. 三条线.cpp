#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;
map<int,bool> dx,dy;
int n;
bool dfs(int cur,int res)
{
	if(res>3)
	return false;
	if(cur==n)
	return true;
	int x=vec[cur].first,y=vec[cur].second;
	if(dx[x]||dy[y])
	return dfs(cur+1,res);
	bool can = 0;
	if(!dx[x])
	{
		dx[x]=true;
		can|=dfs(cur+1,res+1);
		dx[x]=false;
	}
	if(!dy[y])
	{
		dy[y]=true;
		can|=dfs(cur+1,res+1);
		dy[y]=false;
	}
	return can;
}
int main ()
{
	cin>>n;
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		vec.push_back({x,y});
	} 
	cout<<dfs(0,0)<<endl;
	return 0;
}