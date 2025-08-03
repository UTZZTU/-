#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],res,cnt;
void solve()
{
	cnt=0;
	res=1;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		res=res*a[i];
		res%=10;
		if(res==6) cnt++;
	}
	cout<<cnt<<endl;
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