#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,vb,vs,f[110],xu,yu,index;
double tt=100000000,lc=100000000;
void solve()
{
	cin>>n>>vb>>vs;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
//		f[i]+=f[i-1];
	}
	cin>>xu>>yu;
	for(int i=2;i<=n;i++)
	{
		double t=(f[i]*1.0/vb);
		double lcm=(double)sqrt((ll)(f[i]-xu)*(f[i]-xu)*1.0+yu*yu);
		t+=lcm*1.0/vs;
//		cout<<t<<endl;
		if(t<tt)
		{
			tt=t;
			lc=lcm;
			index=i;
		}
		else if(t==tt&&lcm<lc)
		{
			lc=lcm;
			index=i;
		}
	}
	cout<<index<<endl;
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