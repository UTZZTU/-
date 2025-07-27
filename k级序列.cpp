#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,a[200010],b[200010],flag;
bool judge(int x)
{
	int l=a[x]-k,r=a[x]+k;
	if(r<b[x-1]) return false;
	else
	{
		if(l>=b[x-1])
		{
			b[x]=l;
			return true;
		}
		else
		{
			b[x]=b[x-1];
			return true;
		}
	}
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		b[1]=a[1]-k;
		for(int i=2;i<=n;i++)
		{
			if(judge(i))
			{
				;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}