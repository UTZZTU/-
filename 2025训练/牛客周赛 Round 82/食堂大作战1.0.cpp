#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k;
set<int> st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		st.insert(k);
	}
	if(st.size()==n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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