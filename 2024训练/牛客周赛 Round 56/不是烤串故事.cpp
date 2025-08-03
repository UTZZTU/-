#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
const ll MOD = 1e9+7;
const ll BASE = 13331;
ll n,p[1000010],hl[1000010],hr[1000010],h2[1000010];
string s,t,u;
ll gt(ll len)
{
	return h2[len]%MOD;
}
ll gr(ll l,ll r)
{
	return ((hr[l]-hr[r+1]*p[r-l+1]%MOD)%MOD+MOD)%MOD;
}
ll gl(ll l,ll r)
{
//	cout<<hl[r]<<" "<<hl[l-1]<<" "<<p[r-l+1]<<endl;
	return ((hl[r]-hl[l-1]*p[r-l+1]%MOD)%MOD+MOD)%MOD;
}
ll gs(ll x,ll len)
{
//	cout<<"gs"<<x<<" "<<len<<endl;
	return (gr(1ll,x)*p[len-x]%MOD+gl(x+1,len))%MOD;
}
bool check(ll x,ll len)
{
	if(len<=x)
	{
		if(gt(len)==gr(x-len+1,x)) return true;
		else return false;
	}
	else
	{
		if(gt(len)==gs(x,len)) return true;
		else return false;
	}
}
/*
1
1^p +2
1^p^p +2^p+3
*/3
6
baabaa
aabbbb
3
abc
bac
2
ab
cd
void solve()
{
	cin>>n;
	cin>>s;
	cin>>t;
//	u=s;
//	reverse(u.begin(),u.end());
	s=' '+s;
	t=' '+t;
	for(int i=1;i<=n;i++)
	{
		p[i]=(p[i-1]*BASE)%MOD;
		h2[i]=(h2[i-1]*BASE+t[i])%MOD;
		hl[i]=(hl[i-1]*BASE+s[i])%MOD;
//		cout<<h2[i]<<" "<<hl[i]<<endl;
	}
	hr[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		hr[i]=(hr[i+1]*BASE+s[i])%MOD;
//		cout<<hr[i]<<endl;
	}
//	cout<<gt(3)<<endl;
//	cout<<gt(4)<<endl;
//	cout<<gr(1,3)<<endl;
//	cout<<gl(4,4)<<endl;
//	cout<<gs(3,4)<<endl;
	ll maxx=0,pos=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=t[1]) continue;
		ll l=1,r=n;
		while(l<r)
		{
			ll mid=l+r+1>>1;
			if(check(i,mid)) l=mid;
			else r=mid-1;
		}
		if(l>maxx)
		{
			maxx=l;
			pos=i;
		}
	}
	cout<<maxx<<" "<<pos<<endl;
}
/*
123456
321456
327777
*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	p[0]=1;
	while(_--)
	{
		solve();
	}
	return 0;
}