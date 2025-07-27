#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200000];
int pp(int x)
{
	int maxx=0,cnt=1;
	int minn=0x3f3f3f3f3f3f3f3f;
	int pos=n/x;
	for(int i=1;i<=pos;i++)
	{
		int res=0;
		for(int j=1;j<=x;j++)
		{
			res+=a[cnt];
			cnt++;
		}
		maxx=max(maxx,res);
		minn=min(minn,res);
	}
	return maxx-minn;
}
int solve(int n)
{
	vector<int> vec;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			vec.push_back(i);
			vec.push_back(n/i);
		}
	}
	int maxx=0;
	for(int i=0;i<vec.size();i++)
	{
		maxx=max(maxx,pp(vec[i]));
	}
	return maxx;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",solve(n));
	}
	return 0;
}