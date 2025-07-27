#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 10, mod = 998244353;

int n, m, k;
int p[N], q[N];
int tr[N * 2];

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= k; i += lowbit(i)) {
        tr[i]++;
    }
}

int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ret += tr[i];
    }
    return ret;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", q + i);
    }
    k = max(2 * n - 1, m);
    int ret = 0;
    memset(tr, 0, k + 10 << 2);
    for (int i = 0; i < m; i++) {
        ret = (ret + i - query(q[i] + 1)) % mod;
        add(q[i] + 1);
    }
    ret = 1ll * ret * n % mod;
    memset(tr, 0, k + 10 << 2);
    for (int i = 0; i < n; i++) {
        if (m > 18) ret = (ret + (m - 18ll) * (m - 19) / 2 % mod * i) % mod;
        ret = (ret + 1ll * (i - query(p[i])) * m) % mod;
        for (int j = 1; j <= 18 && j < m; j++) {
            ret = (ret + 1ll * (i - query(min((LL)k, (LL)p[i] << j))) * (m - j)) % mod;
            ret = (ret + 1ll * (i - query(p[i] >> j)) * (m - j)) % mod;
        }
        add(p[i]);
    }
    printf("%d\n", ret);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}