#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll s,n,k;
void solve()
{
	cin>>s>>n>>k;
	if(k>n||k*(k-1)/2ll>s)
	{
		cout<<"NO"<<endl;
		return;
	}
	ll t=n-k,sum=s-k*(k-1)/2ll;
	if(t==0)
	{
		if(!sum)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<k;i++) cout<<i<<" ";
			cout<<endl;
		}
		else cout<<"NO"<<endl;
		return;
	}
	if(k==0)
	{
		if(sum>=t)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<k;i++) cout<<i<<" ";
			for(int i=1;i<=t;i++)
			{
				if(i!=t) cout<<1<<" ";
				else cout<<sum-t+1<<" ";
			}
			cout<<endl;
		}
		else cout<<"NO"<<endl;
		return;
	}
	else
	{
		if(sum==1&&k==1||t==1&&sum==k) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i=0;i<k;i++) cout<<i<<" ";
			if(sum==k)
			{
				for(int i=1;i<=t;i++)
				{
					if(i==t-1) cout<<1<<" ";
					else if(i==t) cout<<sum-1<<" ";
					else cout<<0<<" ";
				}
			}
			else
			{
				for(int i=1;i<=t;i++)
				{
					if(i==t) cout<<sum<<" ";
					else cout<<0<<" ";
				}
			}
			cout<<endl;
		}
	}
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