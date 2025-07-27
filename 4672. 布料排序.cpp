#include <bits/stdc++.h>
using namespace std;
int t,n,res;
struct node
{
	string c;
	int d;
	int u;
}s[10010],v[10010];
bool cmp1(node a,node b)
{
	if(a.c==b.c) return a.u<b.u;
	return a.c<b.c;
}
bool cmp2(node a,node b)
{
	if(a.d==b.d) return a.u<b.u;
	return a.d<b.d;
}
int main  ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].c>>s[i].d>>s[i].u;
			v[i].c=s[i].c;
			v[i].d=s[i].d;
			v[i].u=s[i].u;
		}
		sort(s+1,s+1+n,cmp1);
		sort(v+1,v+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(s[i].u==v[i].u) res++;
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}