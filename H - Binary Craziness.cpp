#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n,m,f[1000010],u,v,res,tt[4000010];
vector<ll> vec;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		f[u]++,f[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		tt[f[i]]++;
	}
	for(int i=0;i<=2*m;i++)
	{
		if(tt[i])
		vec.push_back(i);
	}
	for(int i=0;i<vec.size();i++)
	{
		for(int j=i;j<vec.size();j++)
		{
			res=(res+tt[vec[i]]*tt[vec[j]]%mod*((vec[i]^vec[j])*(vec[i]|vec[j])*(vec[i]&vec[j])%mod))%mod;
//			cout<<vec[i]<<" "<<vec[j]<<" "<<(vec[i]^vec[j])*(vec[i]|vec[j])*(vec[i]&vec[j])<<endl;
		}
	}
	cout<<res<<endl;
	return 0;
}