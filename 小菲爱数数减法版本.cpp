#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k;
int main ()
{
	scanf("%lld",&t);
	while(t--){
		ll res=0;
		map<ll,ll> mp;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			for(int j=2;j*j<=k;j++){
				if(k%j==0)
				{
					while(k%j==0)
					k/=j;
					if(mp[j]==0)
					res+=n*(n+1)/2;
					res-=(i-mp[j])*(i-mp[j]-1)/2;
					mp[j]=i;
				}
			}
			if(k>1){
				if(mp[k]==0)
				res+=n*(n+1)/2;
				res-=(i-mp[k])*(i-mp[k]-1)/2;
				mp[k]=i;
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++){
			if(it->second!=n){
				res-=(n-it->second)*(n-it->second+1)/2;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}