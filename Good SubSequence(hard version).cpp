#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],m,x,v,maxx,summ,cnt,tt;
struct node
{
	ll mx,mn,cj;
}s[200010];
bool cmp(node x,node y)
{
	return x.cj>y.cj;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(ll i=2;i<=n;i++)
	{
		s[++cnt].mx=i;
		s[cnt].mn=i-1;
		s[cnt].cj=a[i]*a[i-1];
	}
	sort(s+1,s+1+cnt,cmp);
	maxx=s[1].cj;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld%lld",&x,&v);
		summ=max(v*a[x-1],v*a[x+1]);
		if(summ>=maxx)
		{
			cout<<summ<<endl;
		}
		else
		{
			tt=summ;
			for(int i=1;i<=cnt;i++)
			{
				if(x==s[i].mx||x==s[i].mn)
				{
					continue;
				}
				tt=max(tt,s[i].cj);
				break;
			}
			cout<<tt<<endl;
		}
	}
	return 0;
}