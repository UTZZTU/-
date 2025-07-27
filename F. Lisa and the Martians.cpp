#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,a[200010],pos1,pos2,maxx,res,x;
ll get_len(ll num)
{
	ll res=0;
	while(num)
	{
		res++;
		num/=10;
	}
	return res;
}
bool check(ll num,ll a,ll b)
{
	ll x1=0,x2=0,pos=get_len(num),o=1;
	for(int i=0;i<pos;i++)
	{
		if(num>>i&1)
		{
			if(a>>i&1)
			{
				;
			}
			else
			{
				x1+=o;
			}
			if(b>>i&1)
			{
				;
			}
			else
			{
				x2+=o;
			}
		}
		else
		{
			if(a>>i&1)
			{
				x1+=o;
			}
			else
			{
				;
			}
			if(b>>i&1)
			{
				x2+=o;
			}
			else
			{
				;
			}
		}
		o*=2;
	}
	if(x1==x2) x=x1;
	return x1==x2;
}
ll get_num(ll a,ll b)
{
	ll l=0,r=(ll)pow(2,k)-1;
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(check(mid,a,b)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		maxx=-1;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		{
			res=get_num(a[i],a[i-1]);
			if(res>maxx)
			{
				maxx=res;
				pos1=i-1,pos2=i;
			}
		}
		cout<<a[pos1]<<" "<<a[pos2]<<" "<<x<<endl;
	}
	return 0;
}