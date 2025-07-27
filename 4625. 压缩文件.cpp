#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum,num,js;
struct node
{
	ll a,b,cha;
}s[100010];
bool cmp(node x,node y)
{
	return x.cha>y.cha;
}
int main ()
{
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&s[i].a,&s[i].b);
		s[i].cha=s[i].a-s[i].b;
		sum+=s[i].b;
		num+=s[i].a;
	}
	if(sum>m)
	{
		cout<<-1;
		return 0;
	}
	if(num<=m)
	{
		cout<<js;
		return 0;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		js++;
		num-=s[i].cha;
		if(num<=m)
		{
			cout<<js;
			return 0;
		}
	}
	return 0;
}