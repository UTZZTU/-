#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n;
void solve()
{
	cin>>n;
	ll p=(2*n+2)*n;
	cout<<p-n<<"^2 ";
	for(ll i=p-n+1;i<=p;i++)
	{
		cout<<"+ "<<i<<"^2 ";
	}
	cout<<"="<<endl;
	cout<<p+1<<"^2";
	for(int i=p+2;i<=p+n;i++)
	{
		cout<<" + "<<i<<"^2";
	}
}
// 1 - 4   2 - 12  3 - 24
// 4 6 8
int main ()
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