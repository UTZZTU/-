#include <bits/stdc++.h>
using namespace std;
int n,t,res=2;
pair<int,int> p[1010];
void solve()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	for(int i=2;i<=n;i++)
	{
		double l=p[i-1].first+p[i-1].second/2.0;
		double r=p[i].first-p[i].second/2.0;
		if(r-l>t) res+=2;
		else if(r-l==t) res++;
//		cout<<l<<" "<<r<<endl;
	}
	cout<<res<<endl;
}
int main ()
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