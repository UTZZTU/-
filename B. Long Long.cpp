#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010],res,pos,flag;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res=pos=0;
		flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res+=(ll)abs(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<0)
			{
				if(flag) pos++;
				flag=0;
			}
			else if(a[i]>0)
			{
				flag=1;
			}
		}
		printf("%lld %lld\n",res,pos);
	}
	return 0;
}