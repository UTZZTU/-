#include <bits/stdc++.h>
using namespace std;
int t,n,x,f[100010],k;
struct node
{
	int cnt,pos;
}s[100010];
bool cmp(node a,node b)
{
	if(a.cnt!=b.cnt) return a.cnt<b.cnt;
	return a.pos<b.pos;
}
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&x);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&k);
			s[j].cnt=ceil(k*1.0/x);
			s[j].pos=j;
		}
		sort(s+1,s+1+n,cmp);
		printf("Case #%d:",i);
		for(int j=1;j<=n;j++)
		{
			printf(" %d",s[j].pos);
		}
		printf("\n");
	}
	return 0;
}