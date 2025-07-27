#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,l,n,d,res,num;
char c;
signed main  ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		res=num=0;
		scanf("%lld%lld",&l,&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld %c",&d,&c);
			if(c=='C')
			{
				res+=d;
			} 
			else
			{
				res-=d;
			}
			num+=abs(res)/l;
			res%=l;
		}
		printf("Case #%d: %lld\n",i,num);
	}
	return 0;
}