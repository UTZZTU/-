#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=floor(sqrt(n));i++)
		{
			if(n%i==0)
			ans+=2;
		}
		int u=floor(sqrt(n));
		if(u*u==n)
		ans--;
		cout<<ans<<endl;
	}
	return 0;
}