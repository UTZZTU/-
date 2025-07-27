#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int t,n,m,q,x,op[100010],tr[100010];
pair<int,int> P[100010];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
bool check(int x)
{
	memset(tr,0,sizeof tr);
	for(int i=1;i<=x;i++) add(op[i],1);
	for(int i=1;i<=m;i++)
	{
		int l=P[i].fi,r=P[i].se;
		if(sum(r)-sum(l-1)>(r-l+1>>1)) return true;
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&P[i].fi,&P[i].se);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&op[i]);
		}
		int l=1,r=q,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}