#include <bits/stdc++.h>
using namespace std;
#define int long long//__int128 2^127-1(GCC)
#define PII pair<int,int>
const int inf = 0x3f3f3f3f3f3f3f3f, N = 180 + 5, mod = 1e9 + 7;
map<vector<int>, int>mp;
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(m+1, vector<int>(n+1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int>res(n + 1);
	for (int i = 1; i <= m; i++) {
		map<vector<int>, int>tmp;
		tmp = mp;
		tmp[a[i]] = 1;
		for (auto w : mp) {
			vector<int>p = w.first;
			for (int j = 1; j <= n; j++) {
				res[j] = p[a[i][j]];
			}
			tmp[res]=1;
		}
		mp = tmp;
	}
	cout << mp.size() << '\n';
}