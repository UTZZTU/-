#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int l,d,v,g,r;
double t;
void solve()
{
	cin>>l>>d>>v>>g>>r;
	t+=d*1.0/v;
	double sum=t;
	while(sum>=g+r)
	{
		sum-=g+r;
	}
	if(sum<g)
	{
		t+=(l-d)*1.0/v;
	}
	else
	{
		t+=(g+r)-sum;
		t+=(l-d)*1.0/v;
	}
	cout<<setprecision(10)<<t;
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