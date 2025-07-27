#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int t,n,m,a[N],f[N],cnt,minn,pos;
struct node
{
	int r,w;
}s[N];
bool cmp(node x, node y)
{
	return x.r<y.r;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		minn=0x3f3f3f3f;
		pos=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
//			f[i]=a[i]-a[i-1];
//			f[i]+=a[i];
		}
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld",&s[i].r,&s[i].w);
//			f[1]-=w;
//			f[r+1]+=w;
//			cnt+=w;
		}
		sort(s+1,s+1+m,cmp);
		int j=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<minn)
			{
				minn=a[i];
				pos=i;
			}
			while(j<=m&&i==s[j].r)
			{
				a[pos]-=s[j].w;
				minn-=s[j].w;
				j++;
			}
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];
			printf("%lld ",cnt);
		}
		printf("\n");
	}
	return 0;
}
/*
2
5 2
1 2 3 4 5
3 1
4 2
7 3
4 3 1 10 3 8 6
4 9
3 8
4 5
*/