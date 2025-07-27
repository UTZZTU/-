#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,b,p[1010],s[1010],maxx;
void solve()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				pq.push(p[j]/2+s[i]);
			}
			else pq.push(p[j]+s[j]);
		}
		int cnt=0,pp=b;
		while(!pq.empty())
		{
			int x=pq.top();
			pq.pop();
			if(pp>=x)
			{
				pp-=x;
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx<<endl;
}
signed main ()
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