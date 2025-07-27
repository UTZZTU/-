#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,m,k,x,res=1;
multiset<ll> st;
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		st.insert(x);
	}
	while(k--)
	{
		ll first=*st.begin(),second=*st.rbegin();
		if((first+m)*(second-m)>first*second&&second-m>0)
		{
			st.erase(st.lower_bound(second));
			st.erase(st.begin());
			st.insert(first+m);
			st.insert(second-m);
		}
		else
		break;
	}
	for(auto it=st.begin();it!=st.end();it++){
		res=(res*(*it))%mod;
	}
	cout<<res;
	return 0;
}