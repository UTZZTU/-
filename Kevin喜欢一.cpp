#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int res=0,sum=1;
		while(sum<n)
		{
			sum*=2;
			res++;
		}
		cout<<res<<endl;
	}
	return 0;
}