#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll n,m,a[N],tr1[N],tr2[N],l,r,d;
char op[2];
ll lowbit(ll x)
{
	return x & -x;
}
void add(ll tr[], int x, ll c)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
ll sum(ll tr[], int x)
{
	ll res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
ll pri_ans(ll x)
{
	return sum(tr1,x)*(x+1)-sum(tr2,x);
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		add(tr1,i,a[i]-a[i-1]);
		add(tr2,i,(ll)i*(a[i]-a[i-1]));
	}
	while(m--)
	{
		scanf("%s%lld%lld",op,&l,&r);
		if(*op=='C')
		{
			scanf("%lld",&d);
			add(tr1,l,d),add(tr1,r+1,-d),add(tr2,l,l*d),add(tr2,r+1,-d*(r+1));
		}
		else
		{
			printf("%lld\n",pri_ans(r)-pri_ans(l-1));
		}
	}
	return 0;
}