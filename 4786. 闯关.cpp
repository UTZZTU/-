#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,res;
struct node
{
	ll num,pos; 
}s[110];
bool cmp(node x,node y)
{
	if(x.pos!=y.pos)
	return x.pos<y.pos;
	else
	return x.num>y.num;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		s[i].pos=0;
		scanf("%lld",&s[i].num);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		s[k].pos=1;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(s[i].pos==0)
		res+=s[i].num;
		else
		{
			if(res>s[i].num)
			res*=2;
			else
			res+=s[i].num;
		}
	}
	printf("%lld",res);
	return 0;
}