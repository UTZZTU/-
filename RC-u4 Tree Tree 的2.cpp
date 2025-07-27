#include <bits/stdc++.h>
using namespace std;
vector<int> vec[11];
int f[11][11],vis[11];
set<int> st;
void dfs(int level,int p,int cnt)
{
	if(vis[level])  return;
	vis[level]=1;
	for(auto c:vec[level])
	{
		if(c==p) st.insert(cnt);
		dfs(c,p,cnt+1);
	}
}
int main ()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		st.clear();
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
		{
			vec[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(f[x][y]||f[y][x]) continue;
			f[x][y]=f[y][x]=1;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof vis);
			dfs(i,i,1);
		}
		vector<int> v;
		if(st.size())
		{
			for(auto c:st)
			{
				v.push_back(c);
			}
		}
		if(v.size()==0)
		{
			if(n==1)
			{
				cout<<1<<" "<<0<<endl;
			}
			else
			{
				cout<<2<<" "<<1<<endl;
			}
		}
		else if(v.size()==1)
		{
			if(v[v.size()-1]==2) cout<<2<<" "<<1<<endl;
			else cout<<v[v.size()-1]<<" "<<2<<endl;
		}
		else
		{
			cout<<v[v.size()-1]<<" "<<v[v.size()-2]<<endl;
		}
	}
	return 0;
}
/*
2
5 6
1 2
2 3
3 1
1 4
4 5
5 4
5 5
1 2
2 3
3 4
4 5
5 1

*/
