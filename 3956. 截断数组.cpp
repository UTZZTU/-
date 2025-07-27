#include <bits/stdc++.h>
using namespace std;
int n,a[100010],sum[100010],res1,res2,f[100010];
long long ans;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	if(n<3||sum[n]%3!=0)
	{
		cout<<0;
		return 0;
	}
	res1=sum[n]/3;
	res2=res1*2;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==res1)
		f[i]=1;
		f[i]+=f[i-1];
	}
	for(int i=2;i<n;i++)
	{
		if(sum[i]==res2)
		{
			ans+=(long long)f[i-1];
		}
	}
	cout<<ans;
	return 0;
}