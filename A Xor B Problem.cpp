#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,res;
map<ll,ll> mp;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		mp[k]++;
	} 
	for(auto it=mp.begin();it!=mp.end();it++){
		res+=it->second;
		res+=it->second*(it->second-1);
	}
	cout<<res;
	return 0;
}