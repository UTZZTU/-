#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,q,x,pre,post;
ll lowbit(ll x)
{
	return x & -x;
}
void dfs_left(ll n,ll x)
{
	if(n==x)
	return;
	ll left=n-lowbit(n)/2,right=n+lowbit(n)/2;
	if(x<n)
	{
		pre++;
		dfs_left(left,x);
	}
	else
	{
		pre+=lowbit(n);
		dfs_left(right,x);
	}
}
void dfs_right(ll n,ll x)
{
	if(n==x)
	return;
	ll left=n-lowbit(n)/2,right=n+lowbit(n)/2;
	if(x<n)
	{
		if(n==(ll)pow(2,k))
		{
			post--;
			dfs_right(left,x);
		}
		else
		{
			post-=lowbit(n);
			dfs_right(left,x);
		}		
	}
	else
	{
		post--;
		dfs_right(right,x);
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>k>>q;
	while(q--)
	{
		cin>>x;
		pre=1,post=(ll)pow(2,k);
		dfs_left((ll)pow(2,k),x);
		dfs_right((ll)pow(2,k),x);
		cout<<pre<<" "<<x<<" "<<post<<endl;
	}
	return 0;
}