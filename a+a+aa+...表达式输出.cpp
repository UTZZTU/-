#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[12],n,a,sum;
ll gz(int x)
{
	ll res=0;
	for(int i=1;i<=x;i++)
	{
		res=res*10+a;
	}
	return res;
}
int main ()
{
	cin>>n>>a;
	f[1]=1;
	f[2]=1;
	for(int i=3;i<=10;i++)
	f[i]=f[i-1]+f[i-2];
	for(int i=1;i<=n;i++)
	{
		ll x=gz(f[i]);
		if(i!=1)
		cout<<"+";
		cout<<x;
		sum+=x;
	}
	cout<<"="<<sum;
	return 0;
}