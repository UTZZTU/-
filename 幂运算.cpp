#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,pos=1,num;
ll qmi(ll a,ll p)
{
	ll res=1;
	while(n--)
	{
		a=a*a%p;
	}
	return a%p;
}
int main ()
{
	cin>>n>>p;
	num=qmi((ll)2,p);
	cout<<num;
	return 0;
}
//345678 1223