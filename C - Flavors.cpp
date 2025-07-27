#include <bits/stdc++.h>
using namespace std;
int n,res,maxx;
struct node
{
	int u,v;
}e[300010];
bool cmp(node x,node y)
{
	if(x.v!=y.v) return x.v>y.v;
	return x.u<y.u;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
	}
	sort(e+1,e+1+n,cmp);
	res=e[1].v;
	int i=2;
	for(i;e[i].u==e[1].u;i++)
	{
		maxx=max(maxx,e[i].v/2);
	}
	if(i<=n)
	{
		maxx=max(maxx,e[i].v);
	}
	cout<<res+maxx;
	return 0;
}