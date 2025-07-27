#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100010],b[100010],c[100010],d[100010],e[100010],l[100010],r[100010],res1,res2,pos,ans=0;
struct node{
	int pos,num;
}s[100010];
bool cmp(node a, node b)
{
	return a.num>b.num;
}
int main ()
{
	scanf("%lld",&n);
	pos=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		c[i]=b[i]=a[i];
		b[i]+=b[i-1];
	}
	sort(c+1,c+1+n);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		d[l[i]]++;
		d[r[i]+1]--;
		res1+=b[r[i]]-b[l[i]-1];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=d[i];
		s[i].pos=i;
		s[i].num=ans;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		e[s[i].pos]=c[pos];
		pos--;
	}
	for(int i=1;i<=n;i++)
	{
		e[i]+=e[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		res2+=e[r[i]]-e[l[i]-1];
	}
	printf("%lld",res2-res1);
	return 0;
}