#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll a1,a2,n,cnt;
queue<ll> q;
void solve()
{
	cin>>a1>>a2>>n;
	q.push(a1);q.push(a2);
	for(int i=1;i<=n;i++)
	{
		ll p=q.front();
		q.pop();
		if(i==1) cout<<p;
		else
		cout<<" "<<p;
		p*=q.front();
		string s=to_string(p);
		for(int j=0;j<s.size();j++)
		{
			q.push(s[j]-'0');
		}
	}
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