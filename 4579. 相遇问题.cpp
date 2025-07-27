#include <bits/stdc++.h>
using namespace std;
int a,b,ans;
int main ()
{
	cin>>a>>b;
	if(abs(a-b)&1)
	{
		int l=abs(a-b)/2,r;
		r=l+1;
		ans+=l*(l+1)/2;
		ans+=r*(r+1)/2;
	}
	else
	{
		int l=abs(a-b)/2;
		ans+=l*(l+1);
	}
	cout<<ans;
	return 0;
}