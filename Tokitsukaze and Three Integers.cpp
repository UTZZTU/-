#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
unordered_map<ll,ll> mp2;
ll n,p,a[5010],res,x,s1,s2,d,maxx,t,pos;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main ()
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mp2[a[i]]++;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mp[a[i]*a[j]]+=2;
			maxx=max(maxx,a[i]*a[j]);
		}
	}
	d=exgcd((ll)1,p,s1,s2);
	for(ll i=0;i<p;i++)
	{
		x=s1;
		res=0;
		x*=i;
//		cout<<x<<endl;
		for(int j=1;j<=n;j++)
		{
		    t=x;
			while(t-a[j]<=maxx)
			{
				if((t-a[j])%a[j]==0)
				{
					pos=mp2[(t-a[j])/a[j]]*2;
					if(a[j]*a[j]==(t-a[j]))
					pos-=2;
				}
				else
				pos=0;
				if(mp[(t-a[j])])
				res+=mp[t-a[j]]-pos;
//				if(i==0)
//				{
//					cout<<j<<" "<<a[j]<<" "<<mp[t-a[j]]<<" "<<pos<<" "<<(t-a[j])<<endl;
//				}
				t+=p;
			}
		}
		printf("%lld ",res);
	}
	return 0;
}