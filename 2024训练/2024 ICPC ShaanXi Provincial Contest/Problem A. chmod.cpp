#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x;
void deal(int x)
{
	if((x>>2)&1) cout<<"r";
	else cout<<"-";
	if((x>>1)&1) cout<<"w";
	else cout<<"-";
	if((x>>0)&1) cout<<"x";
	else cout<<"-";
}
void solve()
{
	cin>>x;
	int a=x/100;
	int b=x%100/10;
	int c=x%10;
	deal(a);
	deal(b);
	deal(c);
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}	
	return 0;
}