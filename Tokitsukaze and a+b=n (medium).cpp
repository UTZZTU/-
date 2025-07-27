#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,l1,r1,l2,r2,t1,t2;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1>=n||l2>=n)
		printf("0\n");
		else
		{
			r1=min(r1,n);
			if(r1==n)
			r1--;
			r2=min(r2,n);
			if(r2==n)
			r2--;
			t1=n-l1;
			t2=n-r1;
			printf("%lld\n",max((ll)0,min(t1,r2)-max(t2,l2)+1));
		}
	}
	return 0;
}