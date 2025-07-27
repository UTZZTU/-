#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
	int a,pos,b;
}s[40010];
bool cmp1(node x,node y)
{
	return x.a<y.a;
}
bool cmp2(node x,node y)
{
	return x.pos<y.pos;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i].a);
			s[i].pos=i;
		}
		sort(s+1,s+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			s[i].b=n+1-i;
		}
		sort(s+1,s+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",s[i].b);
		}
		printf("\n");
	}
	return 0;
}
/*
3
1 2 3
3 2 1
-2 0 2
*/