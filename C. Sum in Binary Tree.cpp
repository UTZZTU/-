#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,res;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=1;
		while(n!=1)
		{
			res+=n;
			n>>=1;
		}
		printf("%lld\n",res);
	}
	return 0;
}