#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100010],minn,res,pos;
int get_num(int x,int y)
{
	int jw=0,cnt=0;
	while(x&&y)
	{
		if(jw) cnt++;
		jw=(x%10+y%10+jw)/10;
		x/=10,y/=10;
	}
	while(x)
	{
		if(jw) cnt++;
		jw=(x%10+jw)/10;
		x/=10;
	}
	while(y)
	{
		if(jw) cnt++;
		jw=(y%10+jw)/10;
		y/=10;
	}
	if(jw) cnt++;
	return cnt;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		minn=0x3f3f3f3f;
		pos=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		res=a[1];
		for(int i=2;i<=n;i++)
		{
			pos+=get_num(res,a[i]);
			res+=a[i];
		}
		minn=min(minn,pos);
		pos=0;
		res=a[n];
		for(int i=n-1;i>=1;i--)
		{
			pos+=get_num(res,a[i]);
			res+=a[i];
		}
		minn=min(minn,pos);
		printf("%lld\n",minn);
	}
	return 0;
}