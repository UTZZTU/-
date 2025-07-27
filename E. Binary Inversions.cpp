#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010],f[200010],sum,tt,tot;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1];
			scanf("%lld",&a[i]);
			if(a[i]==1)
			f[i]++;
			if(a[i]==0)
			sum+=f[i];
		}
		tot=sum;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			sum=max(sum,tot-f[i-1]+n-i-(f[n]-f[i]));
			else
			sum=max(sum,tot-(n-i-(f[n]-f[i]))+f[i-1]);
		}
		printf("%lld\n",sum);
	}
	return 0;
}