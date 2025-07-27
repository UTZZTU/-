#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
void solve()
{
	int sum=0;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='+') sum++;
		else sum--;
	}
	cout<<abs(sum)<<endl;
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