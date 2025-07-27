#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,x,m;
int main ()
{
	cin>>n;
	x=floor(sqrt(n));
	ans=x*(4+2*(x-1));
	x*=x;
	if(x==n)
	{
		cout<<ans;
		return 0;
	}
	else
	{
		m=n-x;
		if(m>=sqrt(x)+1)
		{
			ans+=2*3+(m-2)*2;
		}
		else
		{
			ans+=3+(m-1)*2;
		}
		cout<<ans;
	}
	return 0;
}