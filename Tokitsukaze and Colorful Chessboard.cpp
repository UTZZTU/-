#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,maxx,minn,res1,res2;
bool check(ll x){
	maxx=max(a,b);
	minn=min(a,b);
	if(x&1)
	{
		res1=ceil(x*1.0/2);
		res1+=(x/2)*(ceil(x*1.0/2)+x/2);
		res2=res1-1;
	} else {
		res1=(x/2)*(ceil(x*1.0/2)+x/2);
		res2=res1;
	}
	if(res1>=maxx&&res2>=minn)
	return true;
	return false;
}
int main ()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&a,&b);
		if(a==1&&b==0||a==0&&b==1)
		cout<<1<<endl;
		else{
			ll l=2,r=1000000000;
			while(l<r){
				ll mid=(l+r)>>1;
				if(check(mid))
				r=mid;
				else
				l=mid+1;
			}
			cout<<l<<endl;
		}
	}
	return 0;
}