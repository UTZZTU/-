#include<bits/stdc++.h>
using namespace std;

const int inf = 2e9;
const int maxn = 100;
const int maxm = 10050;

int n, m, cost;
int le, ri, mid;
int in[maxn], pre[maxn];
int used[maxn], id[maxn];

struct Edge {
    int from, to, b, c;
    bool ok = true;
    Edge(int f = 0, int t = 0, int bb = 0, int cc = 0) :from(f), to(t), b(bb), c(cc) {}
}edges[maxm], cpy[maxm];

int direct_mst(int root, int V, int E) {
    int ans = 0;
    while (1) { 
        for (int i = 0; i < V; ++i) in[i] = inf;
        for (int i = 0; i < E; ++i) {
            if (!edges[i].ok) continue;
            int u = edges[i].from;
            int v = edges[i].to;
            if (in[v] > edges[i].c && u != v) {
                in[v] = edges[i].c;
                pre[v] = u;
            }
        }

        for (int i = 0; i < V; ++i) {
            if (i == root) continue;
            if (inf == in[i]) return -1;
        }

        int cnt = 0;
        memset(id, -1, sizeof(id)); 
        memset(used, -1, sizeof(used));
        in[root] = 0;
        for (int i = 0; i < V; ++i) {
            ans += in[i];
            int v = i;
            while (used[v] != i && id[v] == -1 && v != root) {
                used[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1) {
                for (int u = pre[v]; u != v; u = pre[u]) id[u] = cnt;
                id[v] = cnt++;
            }
        }

        if (0 == cnt) break;

        for (int i = 0; i < V; i++)
            if (id[i] == -1) id[i] = cnt++;

        for (int i = 0; i < E; i++) {
            if (!edges[i].ok) continue;
            int u = edges[i].from;
            int v = edges[i].to;
            edges[i].from = id[u];
            edges[i].to = id[v];
            if (id[u] != id[v]) edges[i].c -= in[v];
        }
        V = cnt;
        root = id[root];
    }
    return ans;
}

bool check(int x) {
    memcpy(edges, cpy, sizeof(edges));
    for (int i = 0; i < m; ++i) {
        if (edges[i].b >= x) edges[i].ok = true;
        else edges[i].ok = false;
    }
    int ans = direct_mst(0, n, m);
    return ans != -1 && ans <= cost;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int y=1;y<=t;y++) {
        scanf("%d%d%d", &n, &m, &cost);
        le = inf, ri = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, b, c;
            scanf("%d%d%d%d", &u, &v, &b, &c);
            edges[i] = Edge(u, v, b, c);
            cpy[i] = edges[i];
            le = min(le, b);
            ri = max(ri, b);
        }
        if (!check(le)) {
            printf("Case %d: impossible\n",y);
            continue;
        }
        while (le + 1 < ri) {
            mid = (le + ri) >> 1;
            if (check(mid)) le = mid;
            else ri = mid;
        }
        printf("Case %d: %d kbps\n",y,le);
    }
    return 0;
}