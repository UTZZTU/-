#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int c[N], cnt[N];
LL s[N];

LL get(int c, int k) {
    int r = c % k;
    LL ret = 0;
    if (k - r >= 2) ret += (k - r) * (k - r - 1ll) / 2 * (c / k) * (c / k);
    if (r >= 2) ret += r * (r - 1ll) / 2 * ((c + k - 1) / k) * ((c + k - 1) / k);
    ret += 1ll * (k - r) * r * (c / k) * ((c + k - 1) / k);
    return ret;
}

void solve() {
    int n, b, x;
    scanf("%d %d %d", &n, &b, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", c + i);
        cnt[c[i]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= c[i]; j++) {
            s[j] += get(c[i], j);
        }
    }
    LL ret = 0, sum = 0;
    int m = *max_element(c, c + n);
    for (int i = 1; i <= m; i++) {
        ret = max(ret, (s[i] + sum) * b - (i - 1ll) * x);
        sum += get(i, i) * cnt[i];
    }
    printf("%lld\n", ret);
    for (int i = 0; i < n; i++) {
        cnt[c[i]] = 0;
    }
    for (int i = 1; i <= m; i++) {
        s[i] = 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}