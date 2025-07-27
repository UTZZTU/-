#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 200010;

int n, m, k;
ll a[maxn];
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + k + 1);// sort 
	bool ok = false;
	
	// 1. color every col
	ll res = 0, left = 0;
	for (int i = k; i >= 1; --i) {
		ll tmp = a[i] / n;
		tmp = min(tmp, m - res);// 这里是防止剩余的列数不够 
		if (tmp <= 1) {
			continue;
		}
		res += 2;
		left += tmp - 2;// 多的染料存在left 备用 
	}
	ok |= (res + left) >= m;
	
	// 2. color every row
	res = 0;left = 0;
	for (int i = k; i >= 1; --i) {
		ll tmp = a[i] / m;
		tmp = min(tmp, n - res);
		if (tmp <= 1) {
			continue;
		}
		res += 2;
		left += tmp - 2;
	}
	ok |= (res + left) >= n;
	

	printf("%s\n", ok ? "YES" : "NO");
	
}
int main() {
	int t;
	scanf("%d", &t);
//	t = 1;
	while (t--) {
		solve();
	}
}
