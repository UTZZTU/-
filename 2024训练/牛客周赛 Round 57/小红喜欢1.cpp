#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int k;
void solve()
{
	for(int i=1;i<=5;i++)
	{
		cin>>k;
		if(k)
		{
			cout<<i<<endl;
			return;
		}
	}
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