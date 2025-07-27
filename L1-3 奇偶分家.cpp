#include <bits/stdc++.h>
using namespace std;
int res,n,k;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k&1) res++;
	}
	cout<<res<<" "<<n-res;
	return 0;
}