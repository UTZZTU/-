#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll ,vector<ll>,greater<ll> >q;
ll n,d,maxx,x,res;
int main ()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		q.push(x);
	}
	while(!q.empty())
	{
		res++;
		x=q.top();
		q.pop();
		maxx=max(maxx,x);
		if(res&1)
		{
			q.push(x+d);
		}
	}
	cout<<maxx;
	return 0;
}