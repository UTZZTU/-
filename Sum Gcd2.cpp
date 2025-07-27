#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,f[1000010],k,res,gcds[1000010];
int ff=0;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
set<int> st;
map<int,int> mp;
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		gcds[i]=gcd(f[i],k);
		st.insert(gcds[i]);
		mp[gcds[i]]++;
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		int x=*it;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			res+=gcd(f[i],k/x);
//			res%=mod;
		}
		ff+=res*mp[x];
//		ff%=mod;
	}
	printf("%lld\n",ff);
	return 0;
}