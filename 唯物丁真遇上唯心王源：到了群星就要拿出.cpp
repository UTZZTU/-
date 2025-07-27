#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,w,a[1000100],b[1000100],fa[1000100],x,y,res;
map<ll,ll> mp;
vector<ll> vec;
ll find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&w);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),fa[i]=i;
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		if(b[x]==b[y])
		{
			ll eu=find(x),ev=find(y);
			fa[ev]=eu;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			mp[find(i)]+=a[i];
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		vec.push_back(it->second);
	}
	sort(vec.begin(),vec.end());
	ll s=vec.size();
	for(int i=s-1;i>=max(s-k,(ll)0);i--)
	{
		res+=vec[i];
	}
	cout<<res;
	return 0;
}