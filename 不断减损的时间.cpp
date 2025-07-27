#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],res;
ll num(ll x)
{
	while(x&&x%2==0)
	x/=2;
	return x;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=0||a[i]&1)
		res+=a[i];
		else
		res+=num(a[i]);
	}
	cout<<res;
	return 0;
}