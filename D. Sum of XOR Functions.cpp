#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
void solve()
{
	int n; cin >> n;
	vector<int>a(n + 1), s(n + 1); 
	int x, ans = 0;
	for(int i = 1; i <= n; i ++) cin >> x, s[i] = s[i - 1] ^ x;
	for(int k = 0; k <= 30; k ++)
	{
		int cnt0 = 1, cnt1 = 0, s0 = 1, s1 = 0;
		for(int i = 1; i <= n; i ++)
		{
			int tmp = (s[i] >> k) & 1;
			if(tmp)
			{
				ans = (ans + s0 * (1 << k) % mod) % mod;
				cnt1 ++;
			}
			else
			{
				ans = (ans + s1 * (1 << k) % mod) % mod;
				cnt0 ++;
			}
			s0 = (s0 + cnt0) % mod;
			s1 = (s1 + cnt1) % mod; 
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; //cin >> t;
	while(t --) solve(); 
}
/*
3
1 0 1
1 + 1 + 4(1 + 3
a 1 0 1
s 1 1 0
*/