#include <bits/stdc++.h>
using namespace std;
void solve()
{
	pair<int,int> p[10];
	for(int i=1;i<=4;i++) cin>>p[i].first>>p[i].second;
//	cout<<p[1].first<<" "<<p[1].second<<endl;
	sort(p+1,p+1+4);
	cout<<(p[2].second-p[1].second)*(p[3].first-p[2].first)<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}