#include <bits/stdc++.h>
using namespace std;
int x;
void solve()
{
	cin>>x;
	if(x%4)
	{
		cout<<365<<endl;
	}
	else if(x%100)
	{
		cout<<366<<endl;
	}
	else if(x%400)
	{
		cout<<365<<endl;
	}
	else
	{
		cout<<366<<endl;
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