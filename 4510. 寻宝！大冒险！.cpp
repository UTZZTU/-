#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll n,l,s,f[55][55],x,y,res;
bool judge(ll x,ll y)
{
	for(ll i=x;i<=x+s;i++)
	{
		for(ll j=y;j<=y+s;j++)
		{
			if(f[i-x][j-y]!=mp[i*(l+1)+j])
			return false;
		}
	}
	return true;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>l>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		mp[x*(l+1)+y]=1;
	}
	for(int i=s;i>=0;i--)
	{
		for(int j=0;j<=s;j++)
		{
			cin>>f[i][j];
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		x=it->first/(l+1);
		y=it->first%(l+1);
		if(x+s<=l&&y+s<=l)
		{
			if(judge(x,y))
			res++;
		}
	}
	cout<<res;
	return 0;
}