#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,res1,res2,a[200010],b[200010];
struct node
{
	int pos;
	int num;
}f[200010];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res1=res2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res1+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			res2+=b[i];
		}
	    for(int i=1;i<=n;i++)
	    {
	    	f[i].num=a[i]+b[i];
	    	f[i].pos=i;
		}
		sort(f+1,f+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				int pos=f[i].pos;
				res1--;
				res2-=b[pos];
			}
			else
			{
				int pos=f[i].pos;
				res1-=a[pos];
				res2--;
			}
		}
		printf("%lld\n",res1-res2);
	}
	return 0;
}
/*
3 2 4 2 5 5
9 4 7 9 2 5

21 -1 -3 -1 -5 -1 -5
36 -9 -1 -7 -1 -4 -1
*/