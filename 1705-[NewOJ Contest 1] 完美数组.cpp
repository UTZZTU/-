#include <bits/stdc++.h>
using namespace std;
int n,f[1000010],res,maxx,cnt,pre;
bool check(int x)
{
	cnt=pre=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>x)
		{
			if(cnt==0)
			{
				cnt++;
				pre=i;
			}
			else
			{
				cnt++;
				if(cnt%2==0)
				{
					if(f[i]!=f[pre]) return false;
				}
				pre=i;
			}
		}
	}
	if(cnt&1) return false;
	return true;
}
int main ()
{
	scanf("%d",&n);
	maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		maxx=max(maxx,f[i]);
	}
	int l=0,r=maxx;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	res=l;
	maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		maxx=max(maxx,f[i]);
	}
	l=0,r=maxx;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	res=max(res,l);
	cout<<res;
	return 0;
}