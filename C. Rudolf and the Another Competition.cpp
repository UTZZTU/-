#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,h,f[200010];
struct node
{
	ll point,ti,pos;
}s[200010];
bool cmp(node a,node b)
{
	if(a.point!=b.point) return a.point>b.point;
	return a.ti<b.ti;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&h);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&f[j]);
			}
			sort(f+1,f+1+m);
			ll p=0,ti=0,pp=0;
			for(int j=1;j<=m;j++)
			{
				if(pp+f[j]>h)
				{
					break;
				}
				else
				{
					pp+=f[j];
					ti+=pp;
					p++;
				}
			}
			s[i].point=p,s[i].pos=i,s[i].ti=ti;
		}
		sort(s+1,s+1+n,cmp);
		ll cnt=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				cnt++;
				pos=1;
			}
			else
			{
				if(s[i].point==s[i-1].point&&s[i].ti==s[i-1].ti)
				{
					cnt++;
				}
				else
				{
					cnt++;
					pos=cnt;
				}
			}
			if(s[i].pos==1)
			{
				printf("%lld\n",pos);
				break;
			}
		}
	}
	return 0;
}