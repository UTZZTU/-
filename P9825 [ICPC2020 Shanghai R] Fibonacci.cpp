#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
signed main ()
{
	cin>>n;
	int t=n/3;
	res=t*(t+1);
	int r=n-3;
	int l;
	if(n%3==0) l=0;
	else if(n%3==1) l=1;
	else l=2;
	if(l>=0&&r>=0&&r>=l)
	{
		res+=(l+r)*t/2;
	}
	printf("%lld",res);
	return 0;
}