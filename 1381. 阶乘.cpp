#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
int main ()
{
	cin>>n;
	for(int i=n;i>=2;i--)
	{
		ans*=i;
		while(ans%10==0)
		ans/=10;
		ans%=10000;
	}
	cout<<ans%10;
	return 0;
}