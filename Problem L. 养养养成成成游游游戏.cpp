#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,maxx;
struct pp{
	int i,j,op,a,b,d,v;
}s[110];
void dfs(int level,vector<int> vec)
{
	if(level>n)
	{
		int res=0;
		for(int i=1;i<=m;i++)
		{
			if(s[i].op)
			{
				if(s[i].a*vec[s[i].i]+s[i].b*vec[s[i].j]>=s[i].d)
				{
					res+=s[i].v;
				}
			}
			else
			{
				if(s[i].a*vec[s[i].i]+s[i].b*vec[s[i].j]<=s[i].d)
				{
					res+=s[i].v;
				}
			}
		}
		maxx=max(maxx,res);
		return;
	}
	for(int i=0;i<=k;i++)
	{
		vec.push_back(i);
		dfs(level+1,vec);
		vec.pop_back();
	}
}
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d%d%d%d",&s[i].i,&s[i].j,&s[i].op,&s[i].a,&s[i].b,&s[i].d,&s[i].v);
	}
	vector<int> vec;
	vec.push_back(0);
	dfs(1,vec);
	cout<<maxx;
	return 0;
}