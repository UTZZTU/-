#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,o1,o2,o3,o4,u;
ll get_num(ll x)
{
	ll cnt=0;
	for(ll i=1;i<=floor(sqrt(x));i++)
	{
		if(x%i==0) cnt++;
	}
	return cnt;
}
int main ()
{
	cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		ll pos1=get_num(i),pos2=get_num(n-i);
		o1=pos1,o2=pos2,o3=o4=0;
		u=floor(sqrt(i));
		if(u*u==i) o1--,o3++;
		u=floor(sqrt(n-i));
		if(u*u==n-i) o2--,o4++;
//		cout<<pos1<<" "<<pos2<<endl;
		if(o3&&o4) res++;
		if(o3) res+=o2*2;
		if(o4) res+=o1*2;
		res+=o1*o2*2*2;
	}
	cout<<res;
	return 0;
}