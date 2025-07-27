#include <stdio.h>
typedef long long ll;
ll a[1000010];
int main ()
{
	ll n,i,k,m,pd;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	while(m--)
	{
		pd=0;
		scanf("%d",&k);
		for(i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				pd=1;
				break;
			}
			else if(a[i]>k)
			break;
		}
		if(pd==1)
		printf("1 ");
		else
		printf("0 ");
	}
	return 0;
}