#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,l,r,m,x;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		scanf("%lld",&m);
		while(m--)
		{
			scanf("%lld",&x);
			if((l+r)*(r-l+1)/2%x==0)
			printf("0\n");
			else
			printf("1\n");
		}
	}
	return 0;
}