#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k;
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k>31) cout<<n+1<<endl;
		else cout<<min((long long)pow(2,k),n+1)<<endl;
	}
	return 0;
}