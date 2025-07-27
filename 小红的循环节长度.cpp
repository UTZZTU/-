#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q,fact;
map<ll,ll> mp;
bool check(ll x)
{
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i!=2&&i!=5) return false;
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x>1&&x!=2&&x!=5) return false;
	return true; 
}
void num(ll p,ll q)
{
	ll pos=0,cnt=1,len=0;
	p%=q;
	while(1)
	{
		if(mp[p%q]==0)
		mp[p%q]=cnt,p%=q,p*=10;
		else
		{
			len=cnt-mp[p%q];
			pos=mp[p%q]-1;
			break;
		}
		cnt++;
	}
	cout<<pos<<" "<<len<<endl;
}
int main ()
{
	cin>>p>>q;
	fact=__gcd(p,q);
	p/=fact;
	q/=fact;
	if(check(q))
	{
		cout<<"-1";
	}
	else
	{
		num(p,q);
	}
	return 0;
}