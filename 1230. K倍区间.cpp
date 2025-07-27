#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[100010],ans,pre[100010],post[100010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=(pre[i-1]+a[i])%k;
		ans+=post[pre[i]];
		post[pre[i]]++;
	}
	cout<<ans+post[0];
	return 0;
}