#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 10000007;
ll ans,t,n,k;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		priority_queue<ll,vector<ll>,less<ll>> q;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			q.push(k);
		}
		while(q.size()>=2)
		{
			ll a=q.top();
			q.pop();
			ll b=q.top();
			q.pop();
			if(a+b>=0)
			{
				ans+=a+b;
				ans%=INF;
				q.push(a+b);
			}
			else
			break;
		}
		cout<<ans<<endl;
	}
	return 0;
}