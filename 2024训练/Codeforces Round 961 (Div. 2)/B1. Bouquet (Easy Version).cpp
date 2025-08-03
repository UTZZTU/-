#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxx,pt;
struct node
{
	ll a,c;
}s[200010];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
void solve()
{
	map<ll,ll> mp;
	cin>>n>>m;
	maxx=0;
	pt=0;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		mp[x]++;
	}
	for(auto [u,v]:mp)
	{
		s[++pt]={u,v};
	}
	sort(s+1,s+1+pt,cmp);
	for(int i=1;i<=pt;i++)
	{
		if(i==1)
		{
			ll cnt=m/s[i].a;
			cnt=min(cnt,s[i].c);
			maxx=max(maxx,cnt*s[i].a);
		}
		else
		{
			if(s[i].a==s[i-1].a+1)
			{
				ll cnt1=m/s[i-1].a;
				cnt1=min(cnt1,s[i-1].c);
				ll q=m-cnt1*s[i-1].a;
				ll cnt2=q/s[i].a;
				cnt2=min(cnt2,s[i].c);
				ll sum=s[i-1].a*cnt1+cnt2*s[i].a;
				maxx=max(maxx,sum);
				q-=cnt2*s[i].a;
				cnt2=s[i].c-cnt2;
				maxx=max(maxx,sum+max(0ll,min({cnt2,q,cnt1})));
			}
			else
			{
				ll cnt=m/s[i].a;
				cnt=min(cnt,s[i].c);
				maxx=max(maxx,cnt*s[i].a);
			}
		}
	}
	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}