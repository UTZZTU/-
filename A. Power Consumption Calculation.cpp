#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p1,p2,p3,t1,t2,res;
pair<int,int> p[110];
void solve()
{
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		res+=(p[i].second-p[i].first)*p1;
	}
	for(int i=2;i<=n;i++)
	{
		int cnt=p[i].first-p[i-1].second;
		if(cnt<=t1) res+=cnt*p1;
		else  if(cnt<=t1+t2) res+=t1*p1+(cnt-t1)*p2;
		else res+=t1*p1+t2*p2+(cnt-t1-t2)*p3;
	}
	cout<<res<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}