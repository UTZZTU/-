#include <bits/stdc++.h>
using namespace std;
int f[1000010],n,u[1000010],maxx,flag=1;
struct node
{
	int a,pos;
}s[1000010];
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a>y.a;
	else return x.pos<y.pos;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		s[i].a=f[i];
		s[i].pos=i;
		if(f[i]>i) flag=0;
		if(f[i]>maxx+1)
		{
			flag=0;
		}
		maxx=max(maxx,f[i]);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		u[s[i].pos]=n-i+1;
	}
	if(!flag) printf("-1");
	else
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",u[i]);
		}
	}
	return 0;
}