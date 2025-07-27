#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#define cla(a, sum) memset(a, sum, sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2e4+5;
 
ll T,n;
struct node{
	ll l,r;
	ll d;
}f[maxn];
ll sum[maxn],sn[maxn];
 
bool cmp(node u,node v)
{
	if(u.d !=v.d ){
		return u.d <v.d ;
	}
	if(u.d<=0)return u.l <v.l ;
	else return u.r >v.r ;
}
 
int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		ll i,j;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&f[i].l ,&f[i].r );
			f[i].d =f[i].l -f[i].r ;
			if(f[i].d)f[i].d =f[i].d /abs(f[i].d );
		}
		sort(f+1,f+n+1,cmp);
		ll ans=f[1].l +f[1].r ;
		sn[1]=ans;sum[1]=f[1].l ;
		for(i=2;i<=n;i++)
		{
			sum[i]=sum[i-1]+f[i].l ;
			sn[i]=max(sn[i-1],sum[i])+f[i].r ;
			ans=max(ans,sn[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
 } 