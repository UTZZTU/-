#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k;
int main ()
{
	scanf("%lld",&t);
	while(t--){
		ll res=0;
		unordered_map<ll,ll> mp;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			for(int j=2;j*j<=k;j++){
				if(k%j==0)
				{
					res++;
					while(k%j==0)
					k/=j;
					res+=(ll)(n-i);
					res+=(ll)(i-mp[j]-1);
					res+=(ll)(i-mp[j]-1)*(n-i);
					mp[j]=i;
					
				}
			}
			if(k>1){
				res++;
				res+=(ll)(n-i);
				res+=(ll)(i-mp[k]-1);
				res+=(ll)(i-mp[k]-1)*(n-i);
				mp[k]=i;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}