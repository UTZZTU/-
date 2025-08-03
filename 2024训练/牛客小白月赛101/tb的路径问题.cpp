#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
/*
    1 2 3 4 5 6 7 8
1   1 1 1 1 1 1 1 1
2   1 2 1 2 1 2 1 2
3   1 1 3 1 1 3 1 1
4   1 2 1 4 1 2 1 4
5   1 1 1 1 5 1 1 1
6   1 2 3 2 1 6 1 2
7   1 1 1 1 1 1 7 1
8   1 2 1 4 1 2 1 8
*/
// 1-0 2-2 3-4 4-4 5-6 6-4 7-6 8-4
int n;
void solve()
{
	cin>>n;
	if(n==1) cout<<0<<endl;
	else if(n==2)
	{
		cout<<2<<endl;
	}
	else if(n==3) cout<<4<<endl;
	else if(n&1) cout<<6<<endl;
	else cout<<4<<endl;
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