#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll a,b,c;
bool check(ll x,ll y,ll z)
{
	if(x>abs(y-z)&&x<(y+z)&&y>abs(x-z)&&y<(x+z)&&z>abs(y-x)&&x<(y+x)) return true;
	else return false;
}
void solve()
{
	cin>>a>>b>>c;
	if(check(a*2ll,b,c)||check(a,b*2ll,c)||check(a,b,c*2ll)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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