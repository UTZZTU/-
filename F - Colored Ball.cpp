#include <bits/stdc++.h>
using namespace std;
int n,q,k,a,b,fa[200010];
set<int> st[200010];
//int find(int x)
//{
//	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
//	return x;
//	
//}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
//		fa[i]=i;
		scanf("%d",&k);
		st[i].insert(k);
	}
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(st[a].size()>st[b].size())
		{
			st[a].insert(st[b].begin(),st[b].end());
			st[b].clear();
			swap(st[a],st[b]);
		}
		else
		{
			st[b].insert(st[a].begin(),st[a].end());
			st[a].clear();
		}
		printf("%d\n",(int)st[b].size());
	}
	return 0;
}