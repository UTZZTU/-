#include <bits/stdc++.h>
using namespace std;
int ans,n,res=1;
int main ()
{
	cin>>n;
	for(res;res<=n;res*=2)
	{
		ans++;
		n-=res;
	}
	if(n)
	ans++;
	cout<<ans;
	return 0;
}