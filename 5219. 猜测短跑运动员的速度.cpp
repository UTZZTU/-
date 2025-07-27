#include <bits/stdc++.h>
using namespace std;
int n;
double maxx,v;
struct node
{
	int t,x;
}s[100010];
bool cmp(node a,node b)
{
	return a.t<b.t;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].t,&s[i].x);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		v=abs(s[i].x-s[i-1].x)*1.0/(s[i].t-s[i-1].t);
		maxx=max(maxx,v);
	}
	printf("%.6f",maxx);
	return 0;
}