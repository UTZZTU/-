#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
ll n,a[N],tr[N],lower[N],upper[N],res1,res2;
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		lower[i]=query(a[i]-1);
		upper[i]=query(n)-query(a[i]);
		add(a[i],1);
	}
	memset(tr,0,sizeof tr);
	for(int i=n;i>=1;i--)
	{
		res1+=lower[i]*query(a[i]-1);
		res2+=upper[i]*(query(n)-query(a[i]));
		add(a[i],1);
	}
	printf("%lld %lld",res2,res1);
	return 0;
}