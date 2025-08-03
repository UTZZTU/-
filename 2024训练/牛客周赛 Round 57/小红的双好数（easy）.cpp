#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n;
void solve()
{
	cin>>n;
	if(n>2)
	{
		cout<<"YES"<<endl;
		cout<<n-1<<" "<<n<<endl;
	}
	else if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<2<<" "<<3<<endl;
	}
	else cout<<"NO"<<endl;
}
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