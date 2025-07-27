#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve()
{
	cin>>n;
	multiset<int> mul;
	int k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>k;
		mul.insert(k);
//		res+=k;
	}
	if(*mul.begin()==*mul.rbegin())
	{
		cout<<1<<endl;
	}
	else cout<<*mul.rbegin()<<endl;
//	cout<<maxx<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}