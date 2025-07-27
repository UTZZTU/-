#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,k,n,maxx;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k&1) maxx=max(maxx,k);
	}
	cout<<maxx;
	return 0;
}