#include <bits/stdc++.h>
using namespace std;
int n,a,x;
void solve()
{
	cin>>n;
	int maxx=0,minn=0x3f3f3f3f;
	vector<int> vec;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>x;
		if(a==1)
		{
			maxx=max(maxx,x);
		}
		else if(a==2)
		{
			minn=min(minn,x);
		}
		else vec.push_back(x);
	}
	if(maxx>minn)
	{
		cout<<0<<endl;
	}
	else
	{
		int res=minn-maxx+1;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]>=maxx&&vec[i]<=minn) res--;
		}
		cout<<res<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
