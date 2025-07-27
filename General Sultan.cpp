#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 110
#define L 25
#define M 2500
#define S 250010

struct Edge {
    int to, next;
}E[S];

int n, End, tot;
int id[N][L], head[M], len[N];
char weapon[N][L];
bool vis[M];

void AddEdge(int u, int v) {
    E[tot].to = v;
    E[tot].next = head[u];
    head[u] = tot++;
}

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;

    int k = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", weapon[i], weapon[i]);
        len[i] = strlen(weapon[i]);
        for (int j = 0; j < len[i]; j++)
            id[i][j] = k++;
    }
    End = k;

    for (int i = 1; i <= n; i++)
         for (int s = 0; s <= len[i]; s++) 
             for (int j = 1; j <= n; j++) {
                 if (i == j)
                     continue;
                 int t = 0;
                 for (t = 0; t <= len[j] && s + t <= len[i]; t++) 
                     if (weapon[i][s + t] != weapon[j][t])
                         break;
                 if (t >= len[j] && s + t >= len[i])
                     AddEdge(id[i][s], End);
                 else if(t >= len[j])
                     AddEdge(id[i][s], id[i][s + t]);
                 else if(s + t >= len[i])
                     AddEdge(id[i][s], id[j][t]);
             }
}

bool flag;

void dfs(int u) {
    if (u == End) {
        flag = true;
        return;
    }

    vis[u] = true;
    for (int i = head[u]; i != -1; i = E[i].next) {
        int v = E[i].to;
        if (!vis[v])
            dfs(v);
        if (flag)
            return ;
    }
}

int cas = 1;
void solve() {
    memset(vis, 0, sizeof(vis));
    flag = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[id[i][0]])
            dfs(id[i][0]);
        if (flag) break;
    }
    if (!flag)
        printf("Case #%d: Not ambiguous.\n", cas++);
    else
        printf("Case #%d: Ambiguous.\n", cas++);

}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        init();
        solve();
    }
    return 0;
}
