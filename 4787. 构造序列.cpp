#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100010],x,res=1;
int main ()
{
	scanf("%lld%lld",&n,&m);
	if(m<n/2||n==1&&m!=0)
	{
		cout<<-1;
		return 0;
	}
    x=m+1-n/2;
    for(int i=1;i<=n/2;i++)
    {
    	if(i==1)
    	{
    		printf("%lld %lld ",x,x*2);
		}
		else
		{
			while(res==x||res==x*2||res+1==x||res+1==x*2)
			res+=2;
			printf("%lld %lld",res,res+1);
			res+=2;
		}
	}
	if(n&1)
	{
		while(res==x||res==x*2)
		res++;
		printf("%lld",res);
	}
	return 0;
}