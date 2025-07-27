#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
int res,flag;
signed main ()
{
	scanf("%lld",&n);
	flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(res%2!=0)
		{
			if(res>0)
			flag=1;
			else flag=-1;
		}
		if(!flag)
		{
			res=res/2+a[i];
			if(res==0)
			{
				printf("0");
			}
			else if(res>0)
			{
				printf("+");
			}
			else printf("-");
		}
		else if(flag==1)
		{
			res=res/2+a[i];
			if(res>=0)
			{
				printf("+");
			}
			else printf("-");
		}
		else
		{
			res=res/2+a[i];
			if(res<=0)
			{
				printf("-");
			}
			else printf("+");
		}
	}
	
	return 0;
}