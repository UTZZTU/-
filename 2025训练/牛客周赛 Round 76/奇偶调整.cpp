#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,m,k,sum;
ll a[100010];
priority_queue<ll> pq;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
		sum+=a[i];
	}
	while(m>0&&k>0&&pq.size())
	{
		ll x=pq.top();
		pq.pop();
		if(x&1)
		{
			k--;
			x^=1;
			sum--;
		}
		else
		{
			m--;
			x/=2;
			sum-=x;
		}
		if(x!=0)
		pq.push(x);
	}
	while((m>0||k>0)&&pq.size())
	{
		ll x=pq.top();
		pq.pop();
		if(x&1)
		{
			if(k>0)
			{
				k--;
				x^=1;
				sum--;
				pq.push(x);
			}
		}
		else
		{
			if(m>0)
			{
				m--;
				x/=2;
				sum-=x;
				pq.push(x);
			}
		}
	}
	cout<<sum<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}