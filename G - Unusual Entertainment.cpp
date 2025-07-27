#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int head[N], e[M], ne[M], idx;
int tin[N], tout[N], sz;
int p[N];
struct Node {
    int x, y, c, idx;
}q[N * 4];
int tr[N];
int ans[N];

void add(int u, int v) {
    e[idx] = v, ne[idx] = head[u], head[u] = idx++;
}

void dfs(int u, int pre) {
    tin[u] = ++sz;
    for (int i = head[u]; i != -1; i = ne[i]) {
        if (e[i] != pre) {
            dfs(e[i], u);
        }
    }
    tout[u] = sz;
}

int lowbit(int x) {
    return x & -x;
}

void modify(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
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
    memset(head, -1, n + 10 << 2);
    idx = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    sz = 0;
    dfs(1, -1);
    for (int i = 0, j = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int x1 = l, y1 = tin[x], x2 = r, y2 = tout[x];
        q[j++] = {x2, y2, 1, i};
        q[j++] = {x1 - 1, y1 - 1, 1, i};
        q[j++] = {x1 - 1, y2, -1, i};
        q[j++] = {x2, y1 - 1, -1, i};
    }
    sort(q, q + 4 * m, [&](Node &a, Node &b) {
        return a.x < b.x;
    });
    memset(tr, 0, n + 10 << 2);
    memset(ans, 0, n + 10 << 2);
    for (int i = 0, j = 1; i < m << 2; i++) {
        while (j <= n && j <= q[i].x) {
            modify(tin[p[j++]], 1);
        }
        ans[q[i].idx] += q[i].c * query(q[i].y);
    }
    for (int i = 0; i < m; i++) {
        printf("%s\n", ans[i] ? "YES" : "NO");
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}