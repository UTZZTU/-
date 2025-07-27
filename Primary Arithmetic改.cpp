#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,ans,z;
int main ()
{
	while(cin>>x>>y)
	{
		if(x+y==0)
		break;
		z=x+y;
		ans=0;
		while(x||y)
		{
			if(z%10<x%10+y%10)
			ans++;
			z/=10;
			x/=10;
			y/=10;
		}
		if(ans==0)
		cout<<"No carry operation."<<endl;
		else if(ans==1)
		cout<<ans<<" carry operation."<<endl;
		else
		cout<<ans<<" carry operations."<<endl;
	}
	return 0;
}