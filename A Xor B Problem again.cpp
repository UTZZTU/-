#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,t;
map<ll,ll> mp;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		mp[t]++;
	}
	for(auto it1=mp.begin();it1!=mp.end();it1++){
		t=0;
		for(auto it2=mp.begin();it2!=mp.end();it2++){
			if((it1->first^it2->first)==it1->first+it2->first)
			t+=it1->second*it2->second;
		}
		res+=t;
	}
	cout<<res;
	return 0;
}