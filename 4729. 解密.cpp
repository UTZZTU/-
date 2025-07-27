#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,n,d,e,t,x1,x2,tt;
int main ()
{
	scanf("%lld",&k);
	while(k--)
	{
		scanf("%lld%lld%lld",&n,&d,&e);
		t=n-e*d+2;
		tt=sqrt(t*t-4*n);
		if(t*t-4*n<0||tt*tt!=t*t-4*n)
		printf("NO\n");
		else
		{
			
			x1=(t-sqrt(t*t-4*n))/2;
			x2=(t+sqrt(t*t-4*n))/2;
			printf("%lld %lld\n",x1,x2);
		}
	}
	return 0;
}