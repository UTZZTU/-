#include <bits/stdc++.h>
using namespace std;
int t,n,l,r,minn;
char s[300010];
vector<int> vec[300010];
void dfs(int level,int pos)
{
	if(pos>minn) return;
	int u=vec[level][0],v=vec[level][1];
	if(u==0&&v==0)
	{
		minn=min(minn,pos);
		return;
	}
	if(u)
	{
		if(s[level]!='L') dfs(u,pos+1);
		else dfs(u,pos);
	}
	if(v)
	{
		if(s[level]!='R') dfs(v,pos+1);
		else dfs(v,pos);
	}
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			vec[i].clear();
		}
		getchar();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			vec[i].push_back(l);
			vec[i].push_back(r);
		}
		dfs(1,0);
		printf("%d\n",minn);
	}
	return 0;
}