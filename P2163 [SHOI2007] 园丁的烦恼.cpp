#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 5e5 + 10, M = 1e7 + 10;

PII p[N];
struct Node {
    int x, y, c, idx;
}q[N * 4];
int tr[M];
int ans[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i < M; i += lowbit(i)) {
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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        p[i].first++, p[i].second++;
    }
    for (int i = 0, j = 0; i < m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2++, y2++;
        q[j++] = {x2, y2, 1, i};
        q[j++] = {x1 - 1, y1 - 1, 1, i};
        q[j++] = {x2, y1 - 1, -1, i};
        q[j++] = {x1 - 1, y2, -1, i};
    }
    sort(p, p + n);
    sort(q, q + 4 * m, [&](Node &a, Node &b) {
        return a.x < b.x;
    });
    for (int i = 0, j = 0; i < m << 2; i++) {
        while (j < n && p[j].first <= q[i].x) {
            add(p[j++].second, 1);
        }
        ans[q[i].idx] += q[i].c * query(q[i].y);
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}