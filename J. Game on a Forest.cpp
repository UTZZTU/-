#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n, m;
vector<int> e[N];

int fa[N], sz[N], a[N], s[N];

void dfs(int u, int p, int anc)
{
    sz[u] = 1, fa[u] = p, a[u] = anc;
    for (int v : e[u])
    {
        if (v == fa[u]) continue;
        dfs(v, u, anc);
        sz[u] += sz[v];
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T -- )
    {
        cin >> n >> m;
        vector<pair<int, int>> ed;
        for (int i = 0; i < m; i ++ )
        {
            int a, b;
            cin >> a >> b;
            ed.push_back({a, b});
            e[a].push_back(b);
            e[b].push_back(a);
        }
        int sg = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (fa[i] == 0)
            {
                dfs(i, 0, i);
                if (sz[i] & 1) sg ^= 1, s[i] = 1;
                else sg ^= 2, s[i] = 2;
                // cout << sg << ' ';
            }
        }
        // cout << sg << '\n';
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int t = sg; t ^= s[a[i]];
            for (int v : e[i])
            {
                if (fa[i] == v)
                {
                    if (sz[a[i]] - sz[i] & 1) t ^= 1;
                    else t ^= 2;
                }else 
                {
                    if (sz[v] & 1) t ^= 1;
                    else t ^= 2;
                }
            }
            if (!t) 
            {
                ans ++;
            }
        }
        for (auto [u, v] : ed)
        {
            int t = sg; t ^= s[a[u]];
            if (u == fa[v]) swap(u, v);
            if (sz[u] & 1) t ^= 1;
            else t ^= 2;
            if (sz[a[u]] - sz[u] & 1) t ^= 1;
            else t ^= 2;
            if (!t) ans ++;
        }
        cout << ans << '\n';
    }

    return 0;
}