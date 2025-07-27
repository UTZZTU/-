#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,k=1;
int main ()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		k*=i;
		k%=p;
	}
	cout<<k;
	return 0;
}