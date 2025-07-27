#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,p,res,pos,cnt,ff;
struct node
{
	int cnt,val;
}s[100010];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		cnt=0;
		ff=0;
		scanf("%lld%lld",&n,&p);
		pos=n+1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i].cnt);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i].val);
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(s[i].val>p)
			{
				pos=i;
				break;
			}
		}
		int pp=pos;
		for(int i=1;i<pp;i++)
		{
			if(!ff)
			{
				ff=1;
				res+=p;
				cnt=1;
			}
			if(cnt+s[i].cnt<=n)
			{
				res+=s[i].cnt*s[i].val;
				cnt+=s[i].cnt;
				pos=max(pos,cnt);
			}
			else
			{
				int num=n-cnt;
				res+=num*s[i].val;
				pos=n;
				break;
			}
		}
		if(ff)
		pos++;
		for(int i=pos;i<=n;i++)
		{
			res+=p;
		}
		printf("%lld\n",res);
	}
	return 0;
}
