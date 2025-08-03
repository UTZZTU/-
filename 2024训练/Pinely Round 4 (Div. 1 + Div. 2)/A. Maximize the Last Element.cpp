#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100],maxx;
void solve()
{
	maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if((i-1)%2==0&&(n-i)%2==0) maxx=max(maxx,a[i]);
	}
	cout<<maxx<<endl;
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