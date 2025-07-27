#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,k,q,l,r;
int main ()
{
	scanf("%lld%lld%lld",&a,&k,&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		if(k&1)
		{
			if((l-1)&1)
			{
				if(a&1)
				{
					if((r-1)&1)
					{
						printf("-1\n");
					}
					else
					{
						printf("0\n");
					}
				}
				else
				{
					if((r-1)&1)
					{
						printf("1\n");
					}
					else
					{
						printf("0\n");
					}
				}
			}
			else
			{
				if(a&1)
				{
					if((r-1)&1)
					{
						printf("0\n");
					}
					else
					{
						printf("1\n");
					}
				}
				else
				{
					if((r-1)&1)
					{
						printf("0\n");
					}
					else
					{
						printf("-1\n");
					}
				}
			}
		}
		else
		{
			if(a&1) printf("1\n");
			else printf("-1\n");
		}
	}
	return 0;
}