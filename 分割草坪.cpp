#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n;
int main ()
{
	cin>>n;
	if(n==2||n==1)
	cout<<"0";
	else
	{
		ll i=3;
		ans+=6;
		for(i;i<=n-1;i++)
		{
			ans+=i*(i+1);
		}
		cout<<ans;
	}
	return 0;
}