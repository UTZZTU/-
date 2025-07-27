#include <bits/stdc++.h>
using namespace std;

// 2024 OneWan

const int N = 1000005;
int x[N + 5], y[N + 5];
using i64 = long long;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector dpL(n + 5, vector(m + 5, (i64) 1e14));
	vector dpR(n + 5, vector(m + 5, (i64) 1e14));
	for (int i = 1 ; i <= n ; i++) {
		cin >> x[i] >> y[i];
	}
	dpL[0][0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= m ; j++) {
			dpL[i][j] = dpL[i - 1][j];
		}
		for (int j = 0 ; j <= m ; j++) {
			dpL[i][min(m, j + x[i])] = min(dpL[i][min(m, j + x[i])], dpL[i - 1][j] + y[i]);
		}
		for (int j = m - 1 ; j >= 0 ; j--) {
			dpL[i][j] = min(dpL[i][j], dpL[i][j + 1]);
		}
	}
	dpR[n + 1][0] = 0;
	for (int i = n ; i >= 1 ; i--) {
		for (int j = 0 ; j <= m ; j++) {
			dpR[i][j] = dpR[i + 1][j];
		}
		for (int j = 0 ; j <= m ; j++) {
			dpR[i][min(m, j + x[i])] = min(dpR[i][min(m, j + x[i])], dpR[i + 1][j] + y[i]);
		}
		for (int j = m - 1 ; j >= 0 ; j--) {
			dpR[i][j] = min(dpR[i][j], dpR[i][j + 1]);
		}
	}
	i64 ans = 0x7fffffffffffffff;
	for (int i = 1 ; i <= n ; i++) {
		int sum = max(0, m - 2 * x[i]);
		for (int L = 0 ; L <= sum ; L++) {
			i64 res = y[i] / 2 + dpL[i - 1][L] + dpR[i + 1][sum - L];
			ans = min(ans, res);
		}
	}
	cout << ans;
	return 0;
}

