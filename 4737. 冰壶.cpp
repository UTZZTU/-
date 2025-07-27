#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,rs,rh,n,m,cnt,f1,f2;
struct node
{
	int x,y;
	int pos;
	int p;
}s[30];
bool cmp(node x,node y)
{
	return x.p<y.p;
}
bool judge(int x)
{
	if(s[x].p<=(rh+rs)*(rh+rs)) return true;
	return false;
}
signed main  ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		cnt=f1=f2=0;
		scanf("%lld%lld",&rs,&rh);
		scanf("%lld",&n);
		for(int j=1;j<=n;j++)
		{
			cnt++;
			scanf("%lld%lld",&s[cnt].x,&s[cnt].y);
			s[cnt].pos=1;
			s[cnt].p=(s[cnt].x)*(s[cnt].x)+(s[cnt].y)*(s[cnt].y);
		}
		scanf("%d",&m);
		for(int j=1;j<=m;j++)
		{
			cnt++;
			scanf("%lld%lld",&s[cnt].x,&s[cnt].y);
			s[cnt].p=(s[cnt].x)*(s[cnt].x)+(s[cnt].y)*(s[cnt].y);
			s[cnt].pos=2;
		}
		sort(s+1,s+1+cnt,cmp);
		for(int j=1;j<=cnt;j++)
		{
			if(j==1)
			{
				if(judge(j))
				{
					if(s[j].pos==1) f1++;
					else f2++;
				}
			}
			else
			{
				if(s[j].pos==s[j-1].pos)
				{
					if(judge(j))
					{
						if(s[j].pos==1) f1++;
						else f2++;
					}
				}
				else break;
			}
		}
		printf("Case #%lld: %lld %lld\n",i,f1,f2);
	}
	return 0;
}