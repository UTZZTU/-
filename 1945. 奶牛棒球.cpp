#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[1010],res;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	sort(f+1,f+1+n);
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int k=lower_bound(f+1,f+1+n,f[j]*2-f[i])-f;
			if(k>n)
			continue;
			else
			{
				int x=upper_bound(f+1,f+1+n,f[j]*3-f[i]*2)-f;
				res+=x-k;
			}
		}
	}
	printf("%lld",res);
	return 0;
}