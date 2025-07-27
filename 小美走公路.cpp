#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],res,x,y;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		res+=a[i];
		a[i]+=a[i-1];
	}
	cin>>x>>y;
	ll dis=a[max(x,y)-1]-a[min(x,y)-1];
	cout<<min(dis,res-dis);
	return 0;
}