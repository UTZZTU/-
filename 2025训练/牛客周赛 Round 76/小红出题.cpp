#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,sum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%7>=1&&i%7<=5) sum+=3;
	}
	cout<<sum<<endl;
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