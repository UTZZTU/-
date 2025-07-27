#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,f[100010],res,cnt;
vector<int> vec;
signed main ()
{
	scanf("%lld%lld",&n,&k);
	if(n==k)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		if(i>=2)
		{
			vec.push_back(f[i]-f[i-1]);
		}
	}
	res=f[n]-f[1];
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(cnt==k-1)
		{
			break;
		}
		res-=vec[i];
		cnt++;
		if(cnt==k-1)
		{
			break;
		}
	}
	printf("%lld\n",res);
	return 0;
}