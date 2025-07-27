#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main ()
{
	cin>>n;
	if(n&1)
	{
		cout<<4*((n+1)/2)-1;
	}
	else
	{
		cout<<n*2;
	}
	return 0;
}