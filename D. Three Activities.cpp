#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,maxx;
struct node
{
	int pos;
	int num;
}a[100010],b[100010],c[100010];
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
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].num);
			a[i].pos=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i].num);
			b[i].pos=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&c[i].num);
			c[i].pos=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		int pos1,pos2,pos3;
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i].pos!=a[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i].pos!=a[pos1].pos&&c[i].pos!=b[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,a[pos1].num+b[pos2].num+c[pos3].num);
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i].pos!=a[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i].pos!=a[pos1].pos&&b[i].pos!=c[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,a[pos1].num+b[pos3].num+c[pos2].num);
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].pos!=b[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i].pos!=b[pos1].pos&&c[i].pos!=a[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,b[pos1].num+a[pos2].num+c[pos3].num);
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i].pos!=b[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].pos!=b[pos1].pos&&a[i].pos!=c[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,a[pos3].num+b[pos1].num+c[pos2].num);
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i].pos!=c[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].pos!=c[pos1].pos&&a[i].pos!=b[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,a[pos3].num+b[pos2].num+c[pos1].num);
		pos1=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].pos!=c[pos1].pos)
			{
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i].pos!=c[pos1].pos&&b[i].pos!=a[pos2].pos)
			{
				pos3=i;
				break;
			}
		}
		maxx=max(maxx,a[pos2].num+b[pos3].num+c[pos1].num);
		printf("%lld\n",maxx);
	}
	return 0;
}