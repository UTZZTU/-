#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		int x,sum=0,f=0,g=0,minn=0x3f3f3f3f,maxx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			sum+=abs(x);
			if(x<0) f=1;
			else if(x>0) g=1;
			minn=min(minn,x);
			maxx=max(maxx,x);
		}
		if(n==1) printf("%lld\n",x);
		else{
			int ans;
			if(!f) ans=sum-2*minn;
			else if(!g) ans=sum+2*maxx;
			else ans=abs(sum);
			printf("%lld\n",ans);
		}	
	}
	return 0;
}