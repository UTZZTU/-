#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,z,res=1,k;
int main ()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	res=res*i;
	z=2,x=(res-n)*2,y=x-n*z;
	if(y%z==0&&(x-y)%z==0&&(x-y)%n==0&&x-y/z==res)
	{
		cout<<x<<" "<<y<<" "<<z;
		return 0;
	}
	for(int i=1;i<=floor(sqrt(res-n));i++)
	{
		if((res-n)%i==0)
		{
			z=i+1,x=(res-n)/i*z,y=x-n*z;
			if(y%z==0&&(x-y)%z==0&&(x-y)%n==0&&x-y/z==res)
	{
		cout<<x<<" "<<y<<" "<<z;
		return 0;
	}
	z=(res-n)/i+1,x=(res-n)/(z-1)*z,y=x-n*z;
	if(y%z==0&&(x-y)%z==0&&(x-y)%n==0&&x-y/z==res)
	{
		cout<<x<<" "<<y<<" "<<z;
		return 0;
	}
		}
	}
	return 0;
}