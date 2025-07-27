#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 50;
int dp[N][4];//0修奇数, 1修偶数, 2修1,3不修
int a[N]; int v[N], prime[N];
int m;
void is_prime()
{
	for (int i = 2; i < N; i++)
	{
		if (v[i] == 0) { v[i] = i; prime[++m] = i; }
		for (int j = 1; j <= m; j++) { if (prime[j] > v[i] || prime[j] > N / i) break; v[i * prime[j]] = prime[j]; }
	}
}
bool check(int x) { if (v[x] == x) return true; return false; }
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0); is_prime();
	int n; cin >> n; for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][0] = 1, dp[1][1] = 1; dp[1][2] = 1, dp[1][3] = 0; if (a[1] == 1) { dp[1][2] = 0; }
	for (int i = 2; i <= n; i++) {//0修奇数, 1修偶数, 2修1,3不修
		if (a[i] == 1) {//1 -> 偶数和1
			dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]);
		}
		else if (a[i] & 1) {//奇数 -> 偶数
			dp[i][3] = dp[i - 1][1];
		}
		else {//偶数 -> 奇数和1
			dp[i][3] = dp[i - 1][0];
			if (check(a[i] + 1)) {
				dp[i][3] = min(dp[i][3], dp[i - 1][2]);
			}
		}
		if (check(a[i] + a[i - 1])) {// ->不修改
			dp[i][3] = min(dp[i][3], dp[i - 1][3]);
		}
		if (a[i] == 1) {
			dp[i][2] = dp[i][3];
		}
		else {//0修奇数, 1修偶数, 2修1,3不修
			dp[i][2] = min(dp[i - 1][2] + 1, dp[i - 1][1] + 1);//修改为1->1和偶数
			if (check(1 + a[i - 1])) {//->不修改
				dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);
			}
		}
		dp[i][0] = dp[i - 1][1] + 1;//奇数 -> 偶数
		if (a[i - 1] % 2 == 0) {
			dp[i][0] = min(dp[i][0], dp[i - 1][3] + 1);
		}
		dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + 1);//偶数 -> 1和奇数
		if (a[i - 1] % 2 == 1) {
			dp[i][1] = min(dp[i][1], dp[i - 1][3] + 1);
		}
	}
	cout << min({ dp[n][0],dp[n][1],dp[n][2],dp[n][3] });
}