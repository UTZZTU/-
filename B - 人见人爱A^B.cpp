#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod = 1000;
ll a,b;
ll fast_power(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main ()
{
	while(cin>>a>>b)
	{
		if(!a&&!b)
		break;
		cout<<fast_power(a,b,Mod)%1000<<endl;
	}
	return 0;
}