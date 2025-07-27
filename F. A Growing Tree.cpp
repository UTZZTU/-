#include <bits/stdc++.h>

using i64 = long long;
using PII = std::pair<i64,i64>;
#define int i64
#define yes std::cout << "YES\n";
#define no std::cout << "NO\n";

struct SegmentTree {
    const int n;
    struct Node {
        int l, r;
        i64 sum, add;
    };
    std::vector<Node> tr;
    SegmentTree(int n) : n(n), tr(4 << std::__lg(n)) {
        std::function<void(int, int, int)> build = [&](int u, int l, int r) {
            tr[u].l = l, tr[u].r = r;
            if(l == r) tr[u].sum = 0;
            else {
                int mid = l + r >> 1;
                build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
                pushup(u);
            }
        };
        build(1, 1, n);
    }
    SegmentTree(std::vector<i64> init) : SegmentTree(init.size() - 1) {
        
    }
    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; 
    }
    void pushdown(int u) {
        if(tr[u].add) {
            tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add;
            tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
            tr[u << 1].add += tr[u].add;
            tr[u << 1 | 1].add += tr[u].add;
            tr[u].add = 0;
        }
    }
    void modify(int u, int l, int r, i64 k) {
        if(tr[u].l >= l && tr[u].r <= r){
            tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
            tr[u].add += k;
        } else {
            pushdown(u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid) modify(u << 1, l, r, k);
            if(r > mid) modify(u << 1 | 1, l, r, k);
            pushup(u);
        }
    }
    i64 query(int u, int l, int r) {
        if(tr[u].l > r || tr[u].r < l) return 0;
        if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    }
};
//SegmentTree seg(w);  


void solve() {
    int n;
    std::cin >> n;

    int c = 2; //下一个节点的编号
    std::vector<std::array<int,3>> a(n);
    std::vector<std::vector<int>> adj(n + 10);
    for (int i = 0; i < n; i ++) {
        int op, x, y;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            a[i] = {op,x,-1};
            adj[x].push_back(c);
            c ++;
        } else {
            std::cin >> x >> y;
            a[i] = {op,x,y};
        }
    }
    std::vector<int> d(n + 10);//每个节点的时间戳
    std::vector<int> sz(n + 10);//每个点为根的子树大小，包括自己

    int t = 1;
    auto dfs = [&](auto&& dfs,int u) -> int {
        sz[t] = 1;
        d[u] = t;
        t ++;
        int ans = 0;
        for (auto v : adj[u]) {
            ans += dfs(dfs,v);
        }
        sz[d[u]] += ans;
        return sz[d[u]];
    };

    dfs(dfs,1);

    SegmentTree seg(n + 1);

    int k = c;//最大节点,此节点还未被创建

    c = 2;
    for (int i = 0; i < n; i ++) {
        auto [op,x,y] = a[i];
        if (op == 1) {//要把当前节点的值变为0.为了方便，可以先查一次，再加它的相反数
            int l = d[c];
            int va = seg.query(1,l,l);
            seg.modify(1,l,l,-va);
            c ++;
        } else {//节点的时间戳为左区间，时间戳+子树大小 - 1即为右区间
            int l = d[x],r = d[x] + sz[d[x]] - 1;
            seg.modify(1,l,r,y);
            
        }
    }
    for (int i = 1; i <= k - 1; i ++) {
        std::cout << seg.query(1,d[i],d[i]) << " \n"[i == k - 1];
    }

}       

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    
    int T = 1;
    
    std::cin >> T;

    while (T -- ) {
        solve();
    }
    return 0;
}
