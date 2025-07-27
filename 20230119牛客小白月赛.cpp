#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
void solve()
{
	cin>>a>>b>>c>>d;
	double l=a*1.0/(a+b),r=c*1.0/(c+d);
	if(l>r)
	{
		cout<<"S"<<endl;
	}
	else cout<<"Y"<<endl;
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