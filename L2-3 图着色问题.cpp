#include <bits/stdc++.h>
using namespace std;
vector<int> vec[510];
int v,e,k,n,u,o,f[1010];
bool judge(int x)
{
	for(int i=0;i<vec[x].size();i++)
	{
		if(f[x]==f[vec[x][i]]) return false;
	}
	return true;
}
int main ()
{
	cin>>v>>e>>k;
	while(e--)
	{
		cin>>u>>o;
		vec[u].push_back(o);
		vec[o].push_back(u);
	}
	cin>>n;
	while(n--)
	{
		int maxx=0,flag=1;
		set<int> st;
		for(int i=1;i<=v;i++)
		{
			cin>>f[i];
			maxx=max(maxx,f[i]);
			st.insert(f[i]);
		}
		if(st.size()>k||maxx>v)
		{
			printf("No\n");
			continue;
		}
		else
		{
			for(int i=1;i<=v;i++)
			{
				if(!judge(i))
				{
					flag=0;
					break;
				}
			}
		}
		if(!flag) printf("No\n");
		else
		printf("Yes\n");
	}
	return 0;
}