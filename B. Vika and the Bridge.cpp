#include <bits/stdc++.h>
using namespace std;
int t,n,k;
struct node
{
	int v,pos;
}s[200010];
bool cmp(node x,node y)
{
	if(x.v!=y.v) return x.v<y.v;
	return x.pos<y.pos;
}
bool check(int x)
{
	int res=0,pre=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			res+=(s[i].pos-pre-1)/(x+1);
			pre=s[i].pos;
		}
		else
		{
			if(s[i].v!=s[i-1].v)
			{
				res+=(n-pre)/(x+1);
				if(res<=1) return true;
				pre=0;
				res=(s[i].pos-pre-1)/(x+1);
				pre=s[i].pos;
			}
			else
			{
				res+=(s[i].pos-pre-1)/(x+1);
				pre=s[i].pos;
			}
		}
		if(i==n)
		{
			res+=(n-pre)/(x+1);
			if(res<=1) return true;
		}
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i].v);
			s[i].pos=i;
		}
		sort(s+1,s+1+n,cmp);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		int l=0,r=n;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}