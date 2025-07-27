#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
bitset<N> p;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    
    for (int i = 2; i < N; i++) {
        if (p[i]) continue;
        for (int j = i << 1; j < N; j += i) {
            p[j] = 1;
        }
    }
    p[1] = 1;

    int n;
    cin >> n;

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (!p[i] && ans[i] == i) {
            if (i + 1 <= n) swap(ans[i], ans[i + 1]);
            else swap(ans[i], ans[i - 1]);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

    return 0;
}