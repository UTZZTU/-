#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,U,I,hh,mm,ss,tt,sum;
struct node
{
	ll t,u,i;
}s[1010];
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld:%lld:%lld %lld %lld",&hh,&mm,&ss,&U,&I);
		tt=ss+mm*60+hh*60*60;
		s[i].t=tt;
		s[i].u=U;
		s[i].i=I;
	}
	for(int i=2;i<=n;i++)
	sum+=(s[i].t-s[i-1].t)*s[i-1].i*s[i-1].u;
	cout<<sum;
	return 0;
}