#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
	int x,y,pos;
}s[200010];
bool cmp(node a,node b)
{
	if(a.x*b.y-b.x*a.y>0)
	{
		return true;
	}
	else if(a.x*b.y-b.x*a.y<0)
	{
		return false;
	}
	else
	{
		return a.pos<b.pos;
	}
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		s[i].pos=i;
		scanf("%lld%lld",&s[i].x,&s[i].y);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",s[i].pos);
	}
	return 0;
}