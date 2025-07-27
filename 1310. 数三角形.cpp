#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,res;
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll C(ll x)
{
	return x*(x-1)*(x-2)/6;
}
int main ()
{
	cin>>m>>n;
	m++,n++;
	res=C(m*n);
	res-=n*C(m);
	res-=m*C(n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			res-=(gcd(i,j)-1)*(n-i)*(m-j)*2;
		}
	}
	cout<<res;
	return 0;
}