#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define inf 0x3f3f3f3f
#define inff 1e18
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define fi first
#define se second

int solve(vi a) {
	int n = a.size(), ans = inf * 2;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			ans = 0;
			break;
		}
		if (a[i] > a[i + 1]) {
			bool f = true;
			for (int j = i + 1; j < n - 1; j++) {
				if (a[j] > a[j + 1]) {
					f = false;
					break;
				}
			}
			if (f && a[n - 1] <= a[0]) {
				ans = min(ans, n - i - 1);
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			ans = min(ans, 1);
			break;
		}
		if (a[i] < a[i + 1]) {
			bool f = true;
			for (int j = i + 1; j < n - 1; j++) {
				if (a[j] < a[j + 1]) {
					f = false;
					break;
				}
			}
			if (f && a[n - 1] >= a[0]) {
				ans = min(ans, n - i);
			}
			break;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin >> _;
	while (_-- > 0){
		int n;
		cin >> n;
		vi a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = solve(a);
		reverse(a.begin(), a.end());
		ans = min(ans, solve(a) + 1);
		cout << (ans == inf * 2 ? -1 : ans) << endl;
	}
	return 0;
}