#include <bits/stdc++.h>
using namespace std;
int n,k,a,b;
int main ()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&a);
			printf("%d\n",a);
		}
		else
		{
			scanf("%d %d",&a,&b);
			a=__gcd(a,b);
			for(int i=3;i<=k;i++)
			{
				scanf("%d",&b);
				a=__gcd(a,b);
			}
			printf("%d\n",a);
		}
	}
	return 0;
}