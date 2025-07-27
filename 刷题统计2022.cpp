#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,res,ans,tt;
int main ()
{
	cin>>a>>b>>n;
	tt=5*a+2*b;
	ans+=(n/tt)*7;
	n%=tt;
	if(n<=0)
	{
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=5;i++)
	{
		ans++;
		n-=a;
		if(n<=0)
	{
		cout<<ans;
		return 0;
	}
	}
	for(int i=1;i<=2;i++)
	{
		ans++;
		n-=b;
		if(n<=0)
	{
		cout<<ans;
		return 0;
	}
	}
	return 0;
}