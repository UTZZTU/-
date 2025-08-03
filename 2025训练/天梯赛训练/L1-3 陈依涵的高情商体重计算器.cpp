#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
void solve()
{
	cin>>n;
	if(n>100) n=100;
	else
	{
		if(n%10==0) n-=10;
		else n=n/10*10;
	}
	cout<<"Gong xi nin! Nin de ti zhong yue wei: "<<n<<" duo jin";
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