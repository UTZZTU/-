#include <bits/stdc++.h>
using namespace std;
int t,n,a[110];
long long res;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1,j=n;i<=j;i++,j--)
		{
			res+=(a[j]-a[i]);
		}
		printf("%lld\n",res);
	}
	return 0;
}