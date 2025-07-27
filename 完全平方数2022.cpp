#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans,k;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>l>>r;
		ans=floor(sqrt(r))-floor(sqrt(l))+1;
		k=floor(sqrt(l));
		if(k*k<l)
		ans--;
		cout<<ans<<endl;
	}
	return 0;
}