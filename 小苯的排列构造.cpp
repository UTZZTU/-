#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	if(n<=3)
	{
		cout<<-1;
		return;
	}
	deque<int> q;
	q.push_back(2);
	q.push_back(4);
	q.push_back(1);
	q.push_back(3);
	for(int i=5;i<=n;i++)
	{
		if(i&1) q.push_front(i);
		else q.push_back(i);
	}
	for(auto x:q) cout<<x<<" ";
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}