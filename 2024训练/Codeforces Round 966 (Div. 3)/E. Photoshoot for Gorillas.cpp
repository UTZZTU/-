#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,w,a[200010],sum;
void solve()
{
	sum=0;
	cin>>n>>m>>k;
	cin>>w;
	for(int i=1;i<=w;i++) cin>>a[i];
	priority_queue<ll> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			ll cd=min(n,(ll)i+k-1)-max((ll)i,k)+1ll;
			ll kd=min(m,(ll)j+k-1)-max((ll)j,k)+1ll;
			q.push(cd*kd);
//			cout<<i<<" "<<j<<" "<<cd*kd<<endl;
		}
	}
	sort(a+1,a+1+w);
	for(int i=w;i>=1;i--)
	{
//		cout<<q.top()<<endl;
		sum+=q.top()*a[i];
		q.pop();
	}
	cout<<sum<<endl;
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