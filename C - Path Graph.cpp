#include <iostream>
#include <vector>
using namespace std;
int n,m,f[200010],num1,num2,num3,u,v,vis[200010],t;
vector<int> vec[200010];
void dfs(int x)
{
	int num=0,pos;
	for(int i=0;i<vec[x].size();i++)
	{
		if(!vis[vec[x][i]])
		{
			num++;
			pos=vec[x][i];
		}
	}
	if(num!=1)
	return;
	vis[pos]=1;
	dfs(pos);
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
		f[u]++;
		f[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
		  num1++;
		  t=i;
		}
		else if(f[i]==2)
		num2++;
		else
		num3++;
	}
	if(num1==2&&num2==n-2&&num3==0)
	{
		vis[t]=1;
		dfs(t);
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cout<<"No";
				return 0;
			}
		}
		cout<<"Yes";
	}
	else
	cout<<"No";
	return 0;
}