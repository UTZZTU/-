#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec[100];
ll n,m,x,y,visited[100],maxx=1,res;
void dfs(ll num)
{
	for(int i=0;i<vec[num].size();i++)
	{
		if(visited[vec[num][i]])
		continue;
		int j=vec[num][i];
		visited[j]=1;
		res++;
		dfs(j);
	}
	return;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
		continue;
		visited[i]=1;
		res=1;
		dfs(i);
		maxx*=(ll)pow(2,res-1);
	}
	cout<<maxx;
	return 0;
}