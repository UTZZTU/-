#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010];
bool check(int x)
{
	int res=0,pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(pos==-1)
		{
			pos=a[i]+x;
		}
		else
		{
			if(a[i]-x<=pos)
			{
				;
			}
			else
			{
				res++;
				pos=a[i]+x;
			}
		}
		if(res>3) return false;
	}
	res++;
	if(res>3) return false;
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int l=0,r=1e9;
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