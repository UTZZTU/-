#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,d,n,m,k,ans;
double res;
int main ()
{
	cin>>c>>d>>n>>m>>k;
	if(k>=n*m)
	{
		cout<<0;
		return 0;
	}
	res=c*1.0/n;
	if(res>=d)
	{
		cout<<(n*m-k)*d;
		return 0;
	}
	k=n*m-k;
	ans+=k/n*c;
	k%=n;
	if(c>=k*d)
	{
		ans+=k*d;
	}
	else
	ans+=c;
	cout<<ans;
	return 0;
}