#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,m,k,y,res,sum;
void solve()
{
	vector<pair<int,int> >vec;
	cin>>x>>k;
	for(int i=1;i<=k;i++)
	{
		int maxx=0,mn=0;
		sum=0;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>y;
			sum+=y;
			mn=max(mn,-sum);
			if(sum>maxx)
			{
				vec.push_back({mn,sum-maxx});
				maxx=sum;
			}
		}
	}
	sort(vec.begin(),vec.end());
	for(auto [a,b]:vec)
	{
		if(x>=a) x+=b;
		else break;
	}
	cout<<x<<endl;
}
signed main ()
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