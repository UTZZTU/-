#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,h,a[200010],gr,bl,maxx,uu,cnt;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&h);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		gr=2,bl=1;
		maxx=0;
		uu=h;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<h)
			{
				h+=a[i]/2;
				cnt++;
			}
			else
			{
				if(!gr&&!bl)
				break;
				else if(gr)
				{
					gr--;
					h*=2;
					i--;
				}
				else if(!gr&&bl)
				{
					bl--;
					h*=3;
					i--;
				}
			}
		}
		maxx=max(maxx,cnt);
		h=uu;
		cnt=0;
		gr=2,bl=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<h)
			{
				h+=a[i]/2;
				cnt++;
			}
			else
			{
				if(!gr&&!bl)
				break;
				else if(gr==2)
				{
					gr--;
					h*=2;
					i--;
				}
				else if(gr==1&&bl)
				{
					bl--;
					h*=3;
					i--;
				}
				else
				{
					gr--;
					h*=2;
					i--;
				}
			}
		}
		maxx=max(maxx,cnt);
		h=uu;
		cnt=0;
		gr=2,bl=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<h)
			{
				h+=a[i]/2;
				cnt++;
			}
			else
			{
				if(!gr&&!bl)
				break;
				else if(bl)
				{
					bl--;
					h*=3;
					i--;
				}
				else if(gr)
				{
					gr--;
					h*=2;
					i--;
				}
			}
		}
		maxx=max(maxx,cnt);
		printf("%lld\n",maxx);
	}
	return 0;
}