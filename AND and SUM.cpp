#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,s,flag;
ll get_len(ll x)
{
	ll res=0;
	while(x)
	{
		x/=2;
		res++;
	}
	return res;
}
bool check(ll pos)
{
	ll res=2*a,v=s-res;
	for(ll i=pos;i>=0;i--)
	{
//		if((ll)pow(2,i)>=s) continue;
		if(a>>i&1)
		{
//			ll cnt=(ll)pow(2,i)*2;
//			if(v>=cnt)
//			{
//				res+=cnt;
//				v-=cnt;
//			}
//			else return false;
			;
		}
		else
		{
			ll cnt=(ll)pow(2,i);
			if(cnt>v)
			{
				;
			}
			else
			{
				res+=cnt;
				v-=cnt;
			}
			
		}
//		cout<<res<<endl;
	}
	return res==s;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld%lld",&a,&s);
		ll pos=max(get_len(a),get_len(s));
		if(check(pos)) flag=1;
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}