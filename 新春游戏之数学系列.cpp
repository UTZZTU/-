#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<int, int> cnt;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    int ans = 0;
    for (auto [x, v] : cnt) {
        for (auto [y, w] : cnt) {
            ans += 1ll * __gcd(x, y) * v * w * (__builtin_popcount(x) + __builtin_popcount(y)) % mod;
            ans %= mod;
        }    
    }
    cout << ans;
    return 0;
}