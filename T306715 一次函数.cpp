#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,b,x,y,res;
int main ()
{
	scanf("%lld%lld%lld",&n,&k,&b);
	while(n--)
	{
		scanf("%lld%lld",&x,&y);
		if(y==k*x+b)
		res++;
	}
	cout<<res;
	return 0;
}