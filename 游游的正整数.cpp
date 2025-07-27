#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,l,r,t;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&l,&r);
		ll minn=ceil((b-a)*1.0/r),maxx=floor((b-a)*1.0/l);
		if(minn>maxx) cout<<-1<<endl;
		else cout<<minn<<" "<<maxx<<endl;
	}
	return 0;
}