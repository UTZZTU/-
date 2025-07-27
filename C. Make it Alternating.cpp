#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
void solve()
{
	string s; cin >> s;
	int n = s.size();
	int ans = 0, ways = 1;
	for(int l = 0, r = 0; l < n; l = r)
	{
		while(s[l] == s[r] && r < n) r ++;
		ans = (ans + r - l - 1) % mod;
		ways = ways * (r - l) % mod;  
	}
	for(int i = 1; i <= ans; i ++) ways = ways * i % mod;
	cout << ans << " " << ways << '\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t --) solve(); 
}