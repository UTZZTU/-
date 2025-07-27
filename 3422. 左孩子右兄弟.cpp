#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100010];
int n,k,maxx;
int dfs(int x)
{
	int cnt=0;
	int ans=vec[x].size();
	for(int i=0;i<vec[x].size();i++)
	{
		cnt=max(cnt,dfs(vec[x][i])+ans);
	}
	return cnt;
}
int main ()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>k;
		vec[k].push_back(i);
	}
	maxx=dfs(1);
	cout<<maxx<<endl;
	return 0;
}