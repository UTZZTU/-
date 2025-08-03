#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,cnt;
void solve()
{
	while(cin>>n)
	{
		if(n==1) cnt++;
		else if(n==0) cout<<cnt<<endl;
		else break;
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