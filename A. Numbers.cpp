#include <bits/stdc++.h>
using namespace std;
int a,sum,pp;
int num(int base,int x)
{
	int res=0;
	while(x)
	{
		res+=x%base;
		x/=base;
	}
	return res;
}
void solve()
{
	cin>>a;
	pp=a-2;
	for(int i=2;i<=a-1;i++)
	{
		sum+=num(i,a);
	}
	int gcds=__gcd(sum,pp);
	sum/=gcds,pp/=gcds;
	cout<<sum<<"/"<<pp<<endl;
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