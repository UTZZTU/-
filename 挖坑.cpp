#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,k;
int main ()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&n,&k);
		if(k<n+1||k>(n+1)+(n-1)/4*4) printf("-1\n");
		else
		{
			if((k-n-1)&1) printf("-1\n");
			else
			{
				ll t=k-n-1;
				printf("%lld\n",t/4*4+(t%4/2)*3);
			}
		}
	}
	return 0;
}